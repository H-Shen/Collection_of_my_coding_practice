#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    auto fireball = dynamic_cast<Fireball *>(spell);
    if (fireball) {
        fireball->revealFirepower();
        return;
    }
    auto frostbite = dynamic_cast<Frostbite *>(spell);
    if (frostbite) {
        frostbite->revealFrostpower();
        return;
    }
    auto thunderstorm = dynamic_cast<Thunderstorm *>(spell);
    if (thunderstorm) {
        thunderstorm->revealThunderpower();
        return;
    }
    auto waterbolt = dynamic_cast<Waterbolt *>(spell);
    if (waterbolt) {
        waterbolt->revealWaterpower();
        return;
    }
    
    // Longest Common Subsequence: O(A.size()*B.size())
    auto LCS = [](const auto & A, const auto & B) {

        int len_A = static_cast<int>(A.size());
        int len_B = static_cast<int>(B.size());
        if (len_A == 0 || len_B == 0) {
            return 0;
        }
        vector<vector<int> > dp(len_A, vector<int>(len_B));
        for (int a = 0; a < len_A; a++) {
            for (int b = 0; b < len_B; b++) {
                if (a) dp[a][b] = max(dp[a][b], dp[a-1][b]);
                if (b) dp[a][b] = max(dp[a][b], dp[a][b-1]);
                if (A[a] == B[b])
                    dp[a][b] = max(dp[a][b], ((a && b) ? dp[a-1][b-1] : 0) + 1);
            }
        }
        int ret = dp[len_A - 1][len_B - 1];
        return ret;
    };
    cout << LCS(spell->revealScrollName(), SpellJournal::read()) << endl;
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}