#include<iostream>
#include<string>
using namespace std;

long long int p = 998244353; 

long long int gcd(long long int a, long long int b){
    while(b!=0){
        long long int temp = a;
        a = b;
        b = temp%b;
    }
    return a;
}

long long int mod_exp(long long int x, long long int y){
    if(x==1 || y==0)
        return 1;
    long long int temp = mod_exp(x,y/2) % p;
    temp = (temp * temp) % p;
    return (y%2==0)? temp : (temp*x) % p; 
}

long long int mod_inv(long long int x){
    return mod_exp(x,p-2);
}

struct Rational{
    long long int num;
    long long int den;

    Rational(){
        num = 0;
        den = 1;
    }

    Rational(long long int a){
        num = a;
        den = 1;
    }

    Rational(long long int a, long long int b){
        num = a;
        den = b;
    }

    void coprime(){
        long long int temp = gcd(num,den);
        num/=temp;
        den/=temp;
    }

    Rational operator+(Rational const& r){
        Rational out;
        out.num = num*r.den + den *r.num;
        out.den = den * r.den;
        out.coprime();
        return out;
    }

    Rational operator-(Rational const& r){
        Rational out;
        out.num = num*r.den - den *r.num;
        out.den = den * r.den;
        out.coprime();
        return out;
    }

    Rational operator*(Rational const& r){
        Rational out;
        out.num = num * r.num;
        out.den = den * r.den;
        out.coprime();
        return out;
    }

    long long int convert(){
        return (num * mod_inv(den)) % p;
    }

    friend ostream &operator<<(ostream &output, const Rational& r){
        output << r.num << " " << r.den;
    }
    
}; 

struct Node{
    char c;
    long long int prob[4];         //0 is 0, 1 is 1, a is 2, A is 3.
    Node* left;
    Node* right;
    Node(){
        c = '#';
        for(int i=0 ; i<4 ; ++i){
            prob[i] = Rational(1,4).convert();
        }
        left = NULL;
        right = NULL;
    }
    void print(){
        cout << c << "\n";
        if(left!=NULL){
            cout << "(";
            left->print();
            cout << ")\n";
            cout << "(";
            right->print();
            cout << ")\n";
        }
    }
    void printAnswer(){
        for(int i=0 ; i<4 ; ++i)
            cout << prob[i] << " ";
        cout << "\n";
    }
};

Node* parseString(string s){
    int len = s.length();
    if(len==1){
        Node* temp = new Node();
        return temp;
    }
    else{
        int count = 0;
        for(int i=0 ; i<len ; i++){
            if(s[i]=='(') count++;
            else if(s[i]==')') count--;
            else if(count ==1){
                if(s[i]=='^' || s[i]=='&' || s[i]=='|'){
                    Node* temp = new Node();
                    temp->c = s[i];
                    temp->left = parseString(s.substr(1,i-1));
                    temp->right = parseString(s.substr(i+1,len-i-2));
                    
                    if(s[i]=='|'){
                        temp->prob[0] = (temp->left->prob[0] * temp->right->prob[0]);
                        temp->prob[1] = temp->left->prob[1] + temp->right->prob[1] - (temp->left->prob[1] * temp->right->prob[1]) + (temp->left->prob[2] * temp->right->prob[3]) + (temp->left->prob[3] * temp->right->prob[2]);
                        temp->prob[2] = (temp->left->prob[0] * temp->right->prob[2]) + (temp->left->prob[2] * temp->right->prob[0]) + (temp->left->prob[2] * temp->right->prob[2]);
                        temp->prob[3] = Rational(1).convert() - (temp->prob[0] + temp->prob[1] + temp->prob[2]);
                    }
                    else if(s[i]=='&'){
                        temp->prob[0] = temp->left->prob[0] + temp->right->prob[0] - (temp->left->prob[0] * temp->right->prob[0]) + (temp->left->prob[2] * temp->right->prob[3]) + (temp->left->prob[3] * temp->right->prob[2]);
                        temp->prob[1] = (temp->left->prob[1] * temp->right->prob[1]);
                        temp->prob[2] = (temp->left->prob[1] * temp->right->prob[2]) + (temp->left->prob[2] * temp->right->prob[1]) + (temp->left->prob[2] * temp->right->prob[2]);
                        temp->prob[3] = Rational(1).convert() - (temp->prob[0] + temp->prob[1] + temp->prob[2]);
                    }
                    else{
                        temp->prob[0] = temp->left->prob[0] * temp->right->prob[0] + temp->left->prob[1] * temp->right->prob[1] + temp->left->prob[2] * temp->right->prob[2] + temp->left->prob[3] * temp->right->prob[3];
                        temp->prob[1] = temp->left->prob[0] * temp->right->prob[1] +  temp->left->prob[1] * temp->right->prob[0] + temp->left->prob[2] * temp->right->prob[3] + temp->left->prob[3] * temp->right->prob[2];
                        temp->prob[2] = temp->left->prob[0] * temp->right->prob[2] + temp->left->prob[2] * temp->right->prob[0] + temp->left->prob[1] * temp->right->prob[3] + temp->left->prob[3] * temp->right->prob[1];
                        temp->prob[3] = Rational(1).convert() - (temp->prob[0] + temp->prob[1] + temp->prob[2]);
                    }
                    for(int i=0 ; i<4 ; ++i){
                        temp->prob[i] = temp->prob[i]%p;
                        if(temp->prob[i]<0) temp->prob[i] += p;
                    }
                    //cout << s[i] << "\n";
                    //temp->printAnswer();
                    return temp;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Rational r1(1,2);
    //Rational r2(1,4);
    //Rational out = r1 - r2;
    //cout << out.convert() << "\n";
    //long long int out2 =  (r1.convert() - r2.convert()) % p;
    //if(out2 < 0) out2+=p;
    //cout << out2 << "\n";
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Node* root = parseString(s);
        root->printAnswer();
        //cout << "\n";
    }
}
