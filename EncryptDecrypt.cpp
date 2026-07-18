#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

/* ================= FILE UTILITIES ================= */

string readFile(string filename) {
    ifstream in(filename);
    string data((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();
    return data;
}

void writeFile(string filename, string data) {
    ofstream out(filename);
    out << data;
    out.close();
}

void saveKey(string filename, string key) {
    ofstream out(filename);
    out << key;
    out.close();
}

string loadKey(string filename) {
    ifstream in(filename);
    string key;
    getline(in, key);
    in.close();
    return key;
}

/* ================= CAESAR CIPHER ================= */

string caesarEncrypt(string text, int shift) {
    string result="";
    for(char c : text){
        if(isalpha(c)){
            char base = isupper(c) ? 'A':'a';
            result += (c - base + shift)%26 + base;
        } else result += c;
    }
    return result;
}

string caesarDecrypt(string text, int shift){
    return caesarEncrypt(text, 26-shift);
}

/* ================= PLAYFAIR CIPHER ================= */

string prepareText(string text){
    string t="";
    for(char c:text){
        if(isalpha(c)){
            c=toupper(c);
            if(c=='J') c='I';
            t+=c;
        }
    }
    return t;
}

vector<vector<char>> generateMatrix(string key){
    vector<vector<char>> mat(5, vector<char>(5));
    set<char> used;
    string k="";
    for(char c:key){
        c=toupper(c);
        if(c=='J') c='I';
        if(!used.count(c) && isalpha(c)){
            used.insert(c);
            k+=c;
        }
    }
    for(char c='A';c<='Z';c++){
        if(c=='J') continue;
        if(!used.count(c)){
            used.insert(c);
            k+=c;
        }
    }
    int idx=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            mat[i][j]=k[idx++];
    return mat;
}

pair<int,int> findPos(vector<vector<char>>&mat,char c){
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(mat[i][j]==c)
                return {i,j};
    return {-1,-1};
}

string playfairEncrypt(string text,string key){
    text=prepareText(text);
    vector<vector<char>> mat=generateMatrix(key);

    string digraphs="";
    for(int i=0;i<text.size();i++){
        digraphs+=text[i];
        if(i+1<text.size()){
            if(text[i]==text[i+1]) digraphs+='X';
            else digraphs+=text[++i];
        }else digraphs+='X';
    }

    string cipher="";
    for(int i=0;i<digraphs.size();i+=2){
        char a=digraphs[i], b=digraphs[i+1];
        auto p1=findPos(mat,a);
        auto p2=findPos(mat,b);

        if(p1.first==p2.first){
            cipher+=mat[p1.first][(p1.second+1)%5];
            cipher+=mat[p2.first][(p2.second+1)%5];
        }
        else if(p1.second==p2.second){
            cipher+=mat[(p1.first+1)%5][p1.second];
            cipher+=mat[(p2.first+1)%5][p2.second];
        }
        else{
            cipher+=mat[p1.first][p2.second];
            cipher+=mat[p2.first][p1.second];
        }
    }
    return cipher;
}

/* ================= HILL CIPHER (3x3) ================= */

int mod26(int x){
    return (x%26+26)%26;
}

vector<int> multiply(vector<vector<int>>&key, vector<int>&vec){
    vector<int> res(3);
    for(int i=0;i<3;i++){
        res[i]=0;
        for(int j=0;j<3;j++)
            res[i]+=key[i][j]*vec[j];
        res[i]=mod26(res[i]);
    }
    return res;
}

string hillEncrypt(string text, vector<vector<int>>&key){
    string res="";
    for(int i=0;i<text.size();i+=3){
        vector<int> vec(3);
        for(int j=0;j<3;j++)
            vec[j]=toupper(text[i+j])-'A';

        vector<int> enc=multiply(key,vec);
        for(int x:enc) res+=char(x+'A');
    }
    return res;
}

/* ================= MAIN ================= */

int main(){

    string plaintext = readFile("Text_To_Be_Encypted.txt");

    /* -------- Caesar -------- */
    int shift=3;
    saveKey("caesar_key.txt", to_string(shift));

    auto start = high_resolution_clock::now();
    string caesarC = caesarEncrypt(plaintext, shift);
    auto stop = high_resolution_clock::now();
    cout<<"Caesar Encrypt Time: "
        <<duration_cast<microseconds>(stop-start).count()<<" us\n";

    writeFile("caesar_cipher.txt", caesarC);

    start = high_resolution_clock::now();
    string caesarP = caesarDecrypt(caesarC, shift);
    stop = high_resolution_clock::now();
    cout<<"Caesar Decrypt Time: "
        <<duration_cast<microseconds>(stop-start).count()<<" us\n";


    /* -------- Playfair -------- */
    string playfairKey="SECUREKEY";
    saveKey("playfair_key.txt", playfairKey);

    start = high_resolution_clock::now();
    string playfairC = playfairEncrypt(plaintext, playfairKey);
    stop = high_resolution_clock::now();
    cout<<"Playfair Encrypt Time: "
        <<duration_cast<microseconds>(stop-start).count()<<" us\n";

    writeFile("playfair_cipher.txt", playfairC);


    /* -------- Hill -------- */
    vector<vector<int>> hillKey={
        {6,24,1},
        {13,16,10},
        {20,17,15}
    };

    start = high_resolution_clock::now();
    string hillC = hillEncrypt("ACT", hillKey);
    stop = high_resolution_clock::now();
    cout<<"Hill Encrypt Time: "
        <<duration_cast<microseconds>(stop-start).count()<<" us\n";

    writeFile("hill_cipher.txt", hillC);

    return 0;
}
