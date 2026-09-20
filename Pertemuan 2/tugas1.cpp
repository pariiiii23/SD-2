#include <iostream>
using namespace std;

struct Node
{
    int nilai;
    Node *next;
    Node(int v, Node *n = NULL) : nilai(v), next(n) {}
};

Node *head = NULL;

void tampilkanList()
{
    if (head == NULL)
    {
        cout << "List Kosong\n\n";
        return;
    }

    Node *temp = head;
    cout << "Isi Linked List (Head -> Tail): ";
    while (temp != NULL)
    {
        cout << "[" << temp->nilai << "]";
        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }
    cout << " -> NULL\n\n";
}

void tambahAwal(int nilaiBaru)
{
    head = new Node(nilaiBaru, head);
    cout << ">> Berhasil menambahkan " << nilaiBaru << " di awal\n";
    tampilkanList();
}

void tambahAkhir(int nilaiBaru)
{
    Node *newNode = new Node(nilaiBaru);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << ">> Berhasil menambahkan " << nilaiBaru << " di akhir\n";
    tampilkanList();
}

void tambahSetelah(int nilaiCari, int nilaiBaru)
{
    Node *temp = head;

    while (temp != NULL && temp->nilai != nilaiCari)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << ">> Nilai " << nilaiCari << " tidak ditemukan dalam list\n\n";
    }
    else
    {
        temp->next = new Node(nilaiBaru, temp->next);
        cout << ">> Berhasil menambahkan " << nilaiBaru << " setelah nilai " << nilaiCari << "\n";
        tampilkanList();
    }
}

void hapusNilai(int nilaiHapus)
{
    Node *temp = head;
    Node *prev = NULL;

    if (temp->nilai == nilaiHapus)
    {
        head = temp->next;
        delete temp;
        cout << ">> Berhasil menghapus nilai " << nilaiHapus << " dari list\n";
        tampilkanList();
        return;
    }

    while (temp != NULL && temp->nilai != nilaiHapus)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << ">> Nilai " << nilaiHapus << " tidak ditemukan dalam list\n\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << ">> Berhasil menghapus nilai " << nilaiHapus << " dari list\n";
    tampilkanList();
}

void bersihkanMemori()
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = NULL;
}

int main()
{
    int pilihan, nilai, nilaiCari;
    do
    {
        cout << "=== MENU LINKED LIST NILAI MAHASISWA ===\n";
        cout << "1. Tambah Node di Awal\n";
        cout << "2. Tambah Node di Akhir\n";
        cout << "3. Tambah Node Setelah Nilai Tertentu\n";
        cout << "4. Hapus Node Berdasarkan Nilai\n";
        cout << "5. Tampilkan List Saat Ini\n";
        cout << "6. Keluar\n";
        cout << "Pilihan menu (1-6): ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan nilai mahasiswa: ";
            cin >> nilai;
            tambahAwal(nilai);
            break;

        case 2:
            cout << "Masukkan nilai mahasiswa: ";
            cin >> nilai;
            tambahAkhir(nilai);
            break;

        case 3:
            if (head == NULL)
            {
                cout << ">> List kosong\n\n";
                break;
            }
            cout << "Masukkan nilai acuan (sisipkan setelah nilai ini): ";
            cin >> nilaiCari;
            cout << "Masukkan nilai mahasiswa baru: ";
            cin >> nilai;
            tambahSetelah(nilaiCari, nilai);
            break;

        case 4:
            if (head == NULL)
            {
                cout << ">> List Kosong\n\n";
                break;
            }
            cout << "Masukkan nilai yang ingin dihapus: ";
            cin >> nilai;
            hapusNilai(nilai);
            break;

        case 5:
            cout << "\n";
            tampilkanList();
            cout << "Tekan Enter untuk kembali ke menu...";
            cin.ignore(10000, '\n');
            cin.get();
            break;

        case 6:
            bersihkanMemori();
            cout << "Terima kasih, program selesai\n";
            break;

        default:
            cout << "Pilihan tidak valid\n\n";
        }

    } while (pilihan != 6);
    return 0;
}