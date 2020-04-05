#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAX_STR_LENGTH = 1505;
char cstr[MAX_STR_LENGTH];

// A simple implementation of MPQ hash algorithm (Blizzard hash algorithm)
// without compression and encryption
// Reference: https://sfsrealm.hopto.org/inside_mopaq/
namespace MPQ {
    // Constants
    constexpr int MAX_TABLE_SIZE = 100005;
    constexpr unsigned long HASH_OFFSET = 0;
    constexpr unsigned long HASH_A = 1;
    constexpr unsigned long HASH_B = 2;
    constexpr unsigned long CRYPT_TABLE_LENGTH = 0x500;
    // Define the crypt m_Table
    inline static
    array<unsigned long, CRYPT_TABLE_LENGTH> cryptTable;

    // Initialize the crypt m_Table
    inline static
    void initializeCryptTable() {
        unsigned long seed = 0x00100001;
        unsigned long index1;
        unsigned long index2;
        unsigned long i;
        unsigned long temp1;
        unsigned long temp2;
        for (index1 = 0; index1 < 0x100; ++index1) {
            for (index2 = index1, i = 0; i < 5; ++i, index2 += 0x100) {
                seed = (seed * 125 + 3) % 0x2AAAAB;
                temp1 = (seed & 0xFFFF) << 0x10;
                seed = (seed * 125 + 3) % 0x2AAAAB;
                temp2 = (seed & 0xFFFF);
                cryptTable[index2] = (temp1 | temp2);
            }
        }
    }

    // Define the hash function
    inline static
    unsigned long getHash(char *s, unsigned long dwordHashType) {
        auto *key = (unsigned char *) s;
        unsigned long seed1 = 0x7FED7FED;
        unsigned long seed2 = 0xD34D10CC;   // Leet-speak just for fun, I dont want to have a deadlock anyway
        int ch;
        while (*key != 0) {
            ch = toupper(*key);
            ++key;
            seed1 = cryptTable[(dwordHashType << 8) + ch] ^ (seed1 + seed2);
            seed2 = ch + seed1 + seed2 + (seed2 << 5) + 3;
        }
        return seed1;
    }

    // Define the node in the hash table
    template <typename T>
    struct Node {
        unsigned long hash_a;
        unsigned long hash_b;
        bool exists;
        T value;
        Node() : hash_a(0), hash_b(0), exists(false) {}
    };
    // Define the hash table
    template <typename T>
    class HashTable {
    private:
        // members
        int m_Size;
        int m_Elements;
        Node<T> *m_Table;
    public:
        // constructors
        explicit HashTable(int Size) : m_Size(Size), m_Elements(0) {
            if (Size > MAX_TABLE_SIZE) {
                throw invalid_argument("Max length exceeded");
            }
            m_Table = new Node<T>[Size]();
        }
        HashTable() : m_Size(0), m_Elements(0), m_Table(nullptr) {}

        // destructor
        ~HashTable() {
            delete[]m_Table;
            m_Size = 0;
            m_Elements = 0;
            m_Table = nullptr;
        }

        // member functions
        // Insert a string into the hash m_Table
        bool put(char *s, T value = 0) {

            unsigned long hash_main = getHash(s, HASH_OFFSET);
            unsigned long hash_a = getHash(s, HASH_A);
            unsigned long hash_b = getHash(s, HASH_B);

            // Mark the position where we start searching
            unsigned long hash_start_position = hash_main % m_Size;
            unsigned long hash_current_position = hash_start_position;

            while (m_Table[hash_current_position].exists) {
                // If the string is found
                if (m_Table[hash_current_position].hash_a == hash_a &&
                    m_Table[hash_current_position].hash_b == hash_b) {
                    // Update its value
                    m_Table[hash_current_position].value = value;
                    return true;
                }
                hash_current_position = (hash_current_position + 1) % m_Size;
                // If the m_Table is full, return false
                if (hash_current_position == hash_start_position) {
                    return false;
                }
            }
            // Otherwise, insert or update the
            m_Table[hash_current_position].exists = true;
            m_Table[hash_current_position].hash_a = hash_a;
            m_Table[hash_current_position].hash_b = hash_b;
            m_Table[hash_current_position].value = value;
            ++m_Elements;
            return true;
        }

        // Search the string in the hash m_Table, return -1 if not found, otherwise
        // return its position
        int getHashTablePosition(char *s) {

            unsigned long hash_main = getHash(s, HASH_OFFSET);
            unsigned long hash_a = getHash(s, HASH_A);
            unsigned long hash_b = getHash(s, HASH_B);

            // Mark the position where we start searching
            int hash_start_position = static_cast<int>(hash_main % m_Size);

            int hash_current_position = hash_start_position;
            while (m_Table[hash_current_position].exists) {
                if (m_Table[hash_current_position].hash_a == hash_a &&
                    m_Table[hash_current_position].hash_b == hash_b) {
                    return hash_current_position;
                } else {
                    // Access the next slot
                    hash_current_position =
                            (hash_current_position + 1) % m_Size;
                }
                // If searched all slots in the m_Table and the string is
                // not found yet, break the loop
                if (hash_current_position == hash_start_position) {
                    break;
                }
            }
            return -1; // String not found, return -1
        }
        T get(char *s) {
            int position = getHashTablePosition(s);
            // Return T(0) if the key is not found
            if (position == -1) {
                return static_cast<T>(0);
            }
            // Otherwise return its value
            return m_Table[position].value;
        }

        [[nodiscard]] int getCapacity() const {
            return m_Size;
        }

        [[nodiscard]] int getSize() const {
            return m_Elements;
        }
    };
}


int main() {

    MPQ::initializeCryptTable();
    {
        MPQ::HashTable<int> H(MPQ::MAX_TABLE_SIZE);
        int t;
        scanf("%d", &t);
        while (t--) {
            scanf("%s", cstr);
            H.put(cstr);
        }
        printf("%d\n", H.getSize());
    }

    return 0;
}
