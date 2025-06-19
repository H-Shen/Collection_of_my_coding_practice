/*
    cmpdsl: A Fluent, Header-Only Comparator DSL for C++20

    Purpose:
      cmpdsl makes it trivial to build and reuse multi-field comparators
      in modern C++, inspired by Java’s Comparator API. It works seamlessly
      with std::ranges::sort (or std::sort), ordered containers
      (std::set, std::multiset, std::map, std::multimap), and
      policy-based data structures (__gnu_pbds::tree).

    Key Features:
      • Fluent API:
          auto cmp = Comparator<Person>::comparing(&Person::getAge)
                   .thenBy(&Person::getHeight, Order::Desc)
                   .thenBy(&Person::getName);
      • Getter-based:
          Uses pointer-to-getter (R (T::*)() const) so all members can stay private.
      • Header-only & C++20:
          No dependencies beyond <functional>, <vector> and <compare>.
      • Strict Weak Ordering:
          Guarantees correctness in all STL contexts requiring a comparator.

    Getting Started:
      1. Include the header:
           #include "cmp_dsl.hpp"
      2. Define your comparator:
           using namespace cmpdsl;
           auto cmp = Comparator<MyType>::comparing(&MyType::getKey1)
                    .thenBy(&MyType::getKey2)
                    .thenBy(&MyType::getKey3, Order::Desc);
      3. Use with algorithms or containers:
           std::ranges::sort(vec, cmp);
           std::set<MyType, decltype(cmp)> s(cmp);

    With cmpdsl, your comparison logic becomes declarative, reusable, and easy to read.
*/

#ifndef CMP_DSL_HPP
#define CMP_DSL_HPP

#include <vector>
#include <functional>

namespace cmp_dsl {

    enum class Order { Asc, Desc };

    template<typename T>
    class Comparator {
        using CmpFn = std::function<bool(const T&, const T&)>;
        std::vector<CmpFn> comps_;
        Comparator() = default;

    public:
        bool operator()(const T& a, const T& b) const {
            for (auto& cmp : comps_) {
                if (cmp(a,b)) return true;
                if (cmp(b,a)) return false;
            }
            return false;
        }

        template<typename R>
        static Comparator comparing(R (T::*getter)() const,
                                       Order order = Order::Asc)
        {
            Comparator c;
            c.thenBy(getter, order);
            return c;
        }

        template<typename R>
        Comparator& thenBy(R (T::*getter)() const,
                           Order order = Order::Asc)
        {
            comps_.emplace_back(
                [getter,order](const T& a, const T& b){
                    auto ka = (a.*getter)();
                    auto kb = (b.*getter)();
                    return order==Order::Asc ? ka<kb : ka>kb;
                }
            );
            return *this;
        }
    };

} // namespace cmp_dsl

#endif // CMP_DSL_HPP

// Usage:
// class Person {
//     std::string name_;
//     int age_;
//     double height_;
// public:
//     Person(std::string n, const int a, const double h)
//       : name_(std::move(n)), age_(a), height_(h) {}
//     [[nodiscard]] auto getName()   const { return name_; }
//     [[nodiscard]] auto getAge()    const { return age_; }
//     [[nodiscard]] auto getHeight() const { return height_; }
// };
//
// int main(){
//     using namespace cmp_dsl;
//
//     auto cmp = Comparator<Person>::comparing(&Person::getAge)
//              .thenBy(&Person::getHeight, Order::Desc)
//              .thenBy(&Person::getName);
//
//     // vector
//     std::vector<Person> v = {
//         {"Alice",30,1.65}, {"Bob",25,1.80},
//         {"Charlie",25,1.75}, {"Dave",25,1.80}
//     };
//     std::ranges::sort(v, cmp);
//     for(auto& p:v) std::cout<<p.getName()<<" ";
//     std::cout<<"\n";
//
//     // set / multiset / multimap
//     std::set<Person,decltype(cmp)> s(cmp);
//     for(auto& p:v) s.insert(p);
//     std::cout<<"set: "; for(auto& p:s) std::cout<<p.getName()<<" "; std::cout<<"\n";
//     return 0;
// }
