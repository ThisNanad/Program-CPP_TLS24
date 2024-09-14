#include <iostream>
#include <map>
#include <vector>
#include <cctype>   // untuk fungsi toupper

using namespace std;

// Fungsi untuk mendapatkan huruf tengah dari nama
char getHurufTengah(const string& nama) {
    int panjang = nama.length();
    // Jika panjang nama ganjil, ambil karakter tengah
    if (panjang % 2 == 1) {
        return nama[panjang / 2];
    }
    // Jika panjang nama genap, ambil karakter di posisi tengah pertama
    return nama[(panjang / 2) - 1];
}

// Fungsi untuk menghitung jumlah huruf dalam nama (tidak termasuk spasi)
int getJumlahHuruf(const string& nama) {
    int jumlah = 0;
    for (char c : nama) {
        if (isalpha(c)) { // Hanya menghitung huruf alfabet
            jumlah++;
        }
    }
    return jumlah;
}

// Fungsi untuk mencocokkan huruf tengah dan jumlah huruf nama dengan lagu
void kecocokanLagu(const string& nama) {
    // Peta (map) untuk mencocokkan huruf tengah dengan daftar lagu
    map<char, vector<string>> laguMapHuruf;
    
    // Isi peta dengan beberapa contoh huruf dan lagu
    laguMapHuruf['A'] = {"Pop - 'Pura-pura lupa' by Mahen", "Jazz - 'Gelora Cintaku' by Benny Likumahuwa"};
    laguMapHuruf['B'] = {"Pop - 'Sesuatu di Jogja' by Adhitia Sofyan", "Jazz - 'Kasih Tak Sampai' by Tohpati feat. Glenn Fredly"};
    laguMapHuruf['C'] = {"Pop - 'Untungnya, hidup harus tetap berjalan' by Bernadya", "Jazz - 'Aku Cinta Dia' by Erwin Gutawa Jazz Project feat. Dira Sugandi"};
    laguMapHuruf['D'] = {"Pop - 'Tak Segampang itu' by Anggi Marito", "Jazz - 'Manusia Bodoh' by Andien"};
    laguMapHuruf['E'] = {"Pop - 'Satu Bulan' by Bernadya", "Jazz - 'Kepada Hatimu' by Tompi"};
    laguMapHuruf['F'] = {"Pop - 'Gala Bunga Matahari' by Sal Priadi", "Jazz - 'Unforgettable' by Indra Lesmana"};
    laguMapHuruf['G'] = {"Pop - 'Rumah' by Salma Salsabil", "Jazz - 'Sunday Afternoon' by Mocca"};
    laguMapHuruf['H'] = {"Pop - 'Bisa Tanpamu' by Andmesh", "Jazz - 'Bengawan Solo' by Bubi Chen"};
    laguMapHuruf['I'] = {"Pop - 'Mesin Waktu' by Budi Doremi", "Jazz - 'Bulan di Atas Asia' by Balawan"};
    laguMapHuruf['J'] = {"Pop - 'Melawan Restu' by Mahalini", "Jazz - 'Tentang Kamu' by Maliq & D'Essentials"};
    laguMapHuruf['K'] = {"Pop - 'Laskar Pelangi' by Nidji", "Jazz - 'L.O.V.E.' by Tompi"};
    laguMapHuruf['L'] = {"Pop - 'Terima Kasih Cinta' by Afgan", "Jazz - 'Airmata' by Krakatau"};
    laguMapHuruf['M'] = {"Pop - 'Jiwa Yang Bersedih' by Fabio Asher", "Jazz - 'All of Me' by Dira Sugandi "};
    laguMapHuruf['N'] = {"Pop - 'Cinta dan Rahasia' by Yura Yunita", "Jazz - 'Untukku' by Dewa Budjana"};
    laguMapHuruf['O'] = {"Pop - 'Satu-Satu' by Idgitaf", "Jazz - 'Karena Kamu Cuma Satu' by Yura Yunita"};
    laguMapHuruf['P'] = {"Pop - 'Rayuan Perempuan Gila' by Nadin Amizah", "Jazz - 'Serenade' by Indra Lesmana & Eva Celia"};
    laguMapHuruf['Q'] = {"Pop - 'Hati-hati di jalan' by Tulus", "Jazz - 'Senja di Batas Kota' by Abdul & The Coffee Theory"};
    laguMapHuruf['R'] = {"Pop - 'Sempurna' by Andra & The Backbone", "Jazz - 'Juwita Malam' by Ermy Kullit"};
    laguMapHuruf['S'] = {"Pop - 'Cinta Sejati' by Bunga Citra Lestari", "Jazz - 'Menunggu' by Raisa"};
    laguMapHuruf['T'] = {"Pop - 'Sial' by Mahalini", "Jazz - 'Sebuah Lagu' by Tulus"};
    laguMapHuruf['U'] = {"Pop - 'Duka' by Vidi Aldiano", "Jazz - 'Dekat di Hati' by RAN"};
    laguMapHuruf['V'] = {"Pop - 'Lantas' by Juicy Luicy", "Jazz - 'Mau Dibawa Kemana' by Andmesh Kamaleng Jazz"};
    laguMapHuruf['W'] = {"Pop - 'Luka' by Yura Yunita", "Jazz - 'Aku Ingin' by Glenn Fredly"};
    laguMapHuruf['X'] = {"Pop - 'Dunia Tipu-tipu' by Yura Yunita", "Jazz - 'Langit dan Bumi' by Dewa Budjana feat. Shadu Rasjidi"};
    laguMapHuruf['Y'] = {"Pop - 'Pamit' by Tulus", "Jazz - 'We Could Be Together' by Raisa Jazz Version"};
    laguMapHuruf['Z'] = {"Pop - '17' by Tulus", "Jazz - 'It's You' by Eva Celia"};
    
    // Peta (map) untuk mencocokkan jumlah huruf dengan daftar lagu
    map<int, vector<string>> laguMapJumlahHuruf;
    
    // Isi peta dengan contoh jumlah huruf dan lagu
    laguMapJumlahHuruf[3] = {"'Here's Your Perfect' by Jamie Miller"};
    laguMapJumlahHuruf[4] = {"'My Love Mine All Mine' by Mitski"};
    laguMapJumlahHuruf[5] = {"'Drunk Text' by Henry Moodie"};
    laguMapJumlahHuruf[6] = {"'Sorry' by Justin Bieber"};
    laguMapJumlahHuruf[7] = {"'Take Me Out' by Franz Ferdinand"};
    laguMapJumlahHuruf[8] = {"'Sweet Child O' Mine' by Guns N' Roses"};
    laguMapJumlahHuruf[9] = {"'Lose Yourself' by Eminem"};
    laguMapJumlahHuruf[10] = {"'Those Eyes' by New West"};
    laguMapJumlahHuruf[11] = {"'Belong Together' by Mark Ambor"};
    laguMapJumlahHuruf[12] = {"'End of Beginning' by Djo"};
    laguMapJumlahHuruf[13] = {"'Too Sweet' by Lone Tusker"};
    laguMapJumlahHuruf[14] = {"'Dandelions' by Ruth B."};
    laguMapJumlahHuruf[15] = {"'Espresso' by Sabrina Carpenter"};
    laguMapJumlahHuruf[16] = {"'Birds Of A Feather' by Lone Tusker"};
    laguMapJumlahHuruf[17] = {"'Greedy' by Tate McRae"};
    laguMapJumlahHuruf[18] = {"'Glimpse of Us' by Joji"};
    laguMapJumlahHuruf[19] = {"'Angels Like You' by Miley Cyrus"};
    laguMapJumlahHuruf[20] = {"'Scott Street' by Phoebe Bridgers"};
    laguMapJumlahHuruf[21] = {"'Talking to the Moon' by Bruno Mars"};
    laguMapJumlahHuruf[22] = {"'Heartbreak Anniversary' by Lone Tusker"};
    laguMapJumlahHuruf[23] = {"'Someone You Loved' by Lewis Capaldi"};
    laguMapJumlahHuruf[24] = {"'Ghost' by Justin Bieber"};
    laguMapJumlahHuruf[25] = {"'Lunch' by Billie Eilish"};
    laguMapJumlahHuruf[26] = {"'Nonsense' by Sabrina Carpenter"};
    laguMapJumlahHuruf[27] = {"'We Can't Be Friends' by Lone Tusker"};
    laguMapJumlahHuruf[28] = {"'Locked Away' by Lone Tusker"};
    laguMapJumlahHuruf[29] = {"'Starboy' by The Weeknd, Daft Punk"};
    laguMapJumlahHuruf[30] = {"'Cruel Summer' by Taylor Swift"};
    
    // Ambil huruf tengah dari nama dan ubah menjadi huruf kapital
    char hurufTengah = toupper(getHurufTengah(nama));
    
    // Hitung jumlah huruf dalam nama
    int jumlahHuruf = getJumlahHuruf(nama);
    
    // Periksa apakah huruf tengah ada dalam peta
    if (laguMapHuruf.find(hurufTengah) != laguMapHuruf.end()) {
        cout << "Kecocokan lagu untuk huruf tengah dari nama " << nama << " (" << hurufTengah << "):" << endl;
        for (const auto& lagu : laguMapHuruf[hurufTengah]) {
            cout << "- " << lagu << endl;
        }
    } else {
        cout << "Tidak ada kecocokan lagu untuk huruf tengah dari nama " << nama << "." << endl;
    }
    
    // Periksa apakah jumlah huruf ada dalam peta
    if (laguMapJumlahHuruf.find(jumlahHuruf) != laguMapJumlahHuruf.end()) {
        cout << "Kecocokan lagu untuk jumlah huruf dalam nama (" << jumlahHuruf << " huruf):" << endl;
        for (const auto& lagu : laguMapJumlahHuruf[jumlahHuruf]) {
            cout << "- " << lagu << endl;
        }
    } else {
        cout << "Tidak ada kecocokan lagu untuk jumlah huruf dalam nama." << endl;
    }
}

int main() {
    // Input nama pengguna
    string nama;
    cout << "Masukkan nama Anda: ";
    getline(cin, nama);

    // Panggil fungsi kecocokanLagu
    kecocokanLagu(nama);

    return 0;
}
