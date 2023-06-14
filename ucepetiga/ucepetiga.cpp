#include<iostream>
#include<vector>
using namespace std;

class buku {
public:
	string namaBuku;
	buku(string pNamaBuku) :namaBuku(pNamaBuku) {}
};

class penggarang {
public:
	string namapenggarang;
	vector <penerbit*> daftarpenerbit;
	vector <buku*> daftarbuku;
	penggarang(string pNama) : namapenggarang(pNama) {}

	void tambahpenerbit(penerbit*);
	void cetakpenerbit();
	
	void tambahbuku(buku*);
	void cetakbuku();
};

class penerbit {
public:
	string namapenerbit;
	vector<penggarang*> daftarpenggarang;
	penerbit(string pNama) : namapenerbit(pNama) {}

	void tambahpenggarang(penggarang*);
	void cetakpenggarang();
};


void penggarang::tambahpenerbit(penerbit* ppenerbit)
{
	daftarpenerbit.push_back(ppenerbit);
}

void penggarang::cetakpenerbit() {
	cout << "daftar penerbit yang diikuti \"" << this->namapenggarang << "\":\n";
	for (auto& a : daftarpenerbit) {
		cout << a->namapenerbit << "\n";		
	}
	cout << endl;
}

void penggarang::tambahbuku(buku* pbuku) 
{
	daftarbuku.push_back(pbuku);
}

void penggarang::cetakbuku() {
	cout << "daftar buku yang dikarang \"" << this->namapenggarang << "\":\n";
	for (auto& a : daftarbuku) {
		cout << a->namaBuku << "\n";
	}
	cout << endl;
}

void penerbit::tambahpenggarang(penggarang* ppenggarang)
{
	daftarpenggarang.push_back(ppenggarang);
}

void penerbit::cetakpenggarang() {
	cout << "daftar penerbit yang diikuti \"" << this->namapenerbit << "\":\n";
	for (auto& a : daftarpenggarang) {
		cout << a->namapenggarang << "\n";
	}
	cout << endl;
}

int main() {
	penerbit* varpenerbit1 = new penerbit("gama press");
	penerbit* varpenerbit2 = new penerbit("intan pariwara");

	penggarang* varpenggarang1 = new penggarang("joko");
	penggarang* varpenggarang2 = new penggarang("lia");
	penggarang* varpenggarang3 = new penggarang("giga");
	penggarang* varpenggarang4 = new penggarang("asroni");

	buku* varbuku1 = new buku("fisika");
	buku* varbuku2 = new buku("Algoritma");
	buku* varbuku3 = new buku("Basisdata");
	buku* varbuku4 = new buku("Dasar Pemrograman");
	buku* varbuku5 = new buku("Matematika");
	buku* varbuku6 = new buku("Multimedia 1");

	varpenerbit1->tambahpenggarang(varpenggarang1);
	varpenerbit1->tambahpenggarang(varpenggarang2);
	varpenerbit1->tambahpenggarang(varpenggarang3);

	varpenerbit2->tambahpenggarang(varpenggarang4);
	varpenerbit2->tambahpenggarang(varpenggarang3);

	varpenggarang3->tambahpenerbit(varpenerbit1);
	varpenggarang3->tambahpenerbit(varpenerbit2);

	varpenggarang1->tambahbuku(varbuku1);
	varpenggarang1->tambahbuku(varbuku2);
	varpenggarang2->tambahbuku(varbuku3);
	varpenggarang4->tambahbuku(varbuku4);
	varpenggarang3->tambahbuku(varbuku5);
	varpenggarang3->tambahbuku(varbuku6);

	varpenerbit1->cetakpenggarang();
	varpenerbit2->cetakpenggarang();
	varpenggarang3->cetakpenerbit();

	return 0;
}


