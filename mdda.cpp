#include <bits/stdc++.h>
using namespace std;

class sinhVien{
private:
    string id, name, ns;
    double gpa;
    static int count;
public:
    friend istream& operator >> (istream &in, sinhVien &a);
    friend ostream& operator << (ostream &out, sinhVien a);
    void tangCount(){
        count++;
    }
    friend void chuanHoa(sinhVien &a);
    bool operator < (sinhVien x);
};

bool sinhVien::operator<(sinhVien x){
    return this->gpa < x.gpa;
}

istream& operator >> (istream &in, sinhVien &a){
    a.count++;
    a.id = "SV " + string(3-to_string(a.count).length(), '0') + to_string(a.count);
    cout << "Name: ";
    in.ignore();
    getline(in, a.name);
    cout << "Birthday: ";
    in>>a.ns;
    cout << "GPA: ";
    in>>a.gpa;
    return in;
}

ostream& operator << (ostream &out, sinhVien a){
    out << a.id << ": " << a.name << " " << a.ns << " " << fixed << setprecision(2) << a.gpa << endl;
    return out;
}

void chuanHoa(sinhVien &a){
    string tmp = a.name;
    // chuyển tất cả thành chữ thường
    for(int i=0; i<tmp.size(); i++)
        if(tmp[i]>=65 && tmp[i]<=90)
            tmp[i] += 32;
    // xóa khoảng trắng thừa
    string ans = "";
    bool check = true;
    for(int i=0; i<tmp.size(); i++){
        if(tmp[i]!=' '){
            ans += tmp[i];
            check = false;
        }
        else if(!check){
            ans += tmp[i];
            check = true;
        }
    }
    // viết hoa chữ cái đầu mỗi từ
    if(ans[0]>=97)
        ans[0] = ans[0] - 32;
    for(int i=1; i<ans.size(); i++){
        if(ans[i]==' ' && ans[i+1]!=' ')
            if(ans[i+1]>=97)
                ans[i+1] = ans[i+1] - 32;
    }
    a.name = ans;
}

int sinhVien::count = 0;

int main(){
    int n;
    cin>>n;
    sinhVien *a = new sinhVien[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a, a+n);
    for(int i=0; i<n; i++)
        cout << a[i];

    return 0;
}