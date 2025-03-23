# NYOBA

# PROYEK-2 - Pengembangan Aplikasi Berbasis Library

## Teknik Komputer dan Informatika - D3 Teknik Informatika 
## Manager Proyek: Djoko Cahyo Utomo Lieharyani, S.Kom., M.MT
## Nama Kelompok: C3-*Space Invaders*
### Anggota Kelompok:

| Nama | NIM |
| ---- | --- |
| Alda Pujama | 241511066 |
| Fairuz Sheva Muhammad | 241511073 |
| Gema Adzan Firdaus | 241511075 |
| Muhammad Ihsan Ramadhan | 241511083 |
| Rahma Attaya Tamimah | 241511088 |

# Deskripsi
Space Invaders adalah game di mana pemain mengendalikan pesawat luar angkasa dan bertugas menghancurkan musuh yang datang berdasarkan wave. Terdapat dua jenis musuh dalam permainan ini: musuh biasa dengan HP rendah dan musuh kuat dengan HP lebih tinggi, yang bergerak dari kanan ke kiri layar. Untuk membantu pemain bertahan lebih lama, permainan ini menyediakan power-up yang dapat menambah nyawa dan amunisi. Dalam permainan ini, pesawat dikendalikan langsung melalui keyboard. Pemain dapat menembak dengan sistem yang memiliki jeda (cooldown) dan harus melakukan reload jika amunisi habis. Musuh muncul secara acak dengan variasi posisi dan kecepatan, sehingga masing-masing memiliki pola pergerakan yang berbeda. Setelah satu gelombang musuh dikalahkan, jumlah musuh akan bertambah dan tingkat kesulitannya meningkat. Sistem collision detection akan mendeteksi benturan antara peluru dan musuh atau antara pesawat dan musuh, yang akan mempengaruhi jumlah nyawa dan skor pemain.

# Fitur Game dan Pembagian Tugas:
### 1.  M. Ihsan Ramadhan - Bertanggung jawab dalam pengembangan sistem pesawat pemain, peluru, dan power-up (buff), yaitu:
    A. Sistem Pesawat Pemain
        1. Gerakan Pesawat
            a). Mengatur pergerakan pesawat menggunakan input pemain (WASD).
            b). Menentukan batas gerakan agar pesawat tidak keluar dari layar.
        2. Penanganan Tabrakan dengan Suplai
            a). Memeriksa apakah pesawat menabrak power-up (buff).
            b). Menambahkan efek ketika suplai diambil, seperti menambah nyawa atau amunisi.
        3. Efek Visual Pesawat
            a). Membuat tampilan pesawat dengan SDL_Renderer.
            b). Membuat efek api beranimasi di bagian belakang pesawat; jika pesawat diam, apinya kecil, dan jika bergerak, apinya membesar.
    B. Sistem Peluru
        1. Membuat Visualisasi Peluru
            a). Mengatur ukuran dan warna peluru beserta trail (ekor).
        2. Menembakkan Peluru, Mengatur Kecepatan dan Jalurnya
            a). Membuat fungsi nembak() agar pesawat bisa menembakkan peluru.
            b). Mengatur kecepatan peluru menggunakan dx dan dy, memastikan peluru menghilang saat               keluar dari layar.
        3. Menambah Amunisi dan Menampilkan Amunisi
            a). Menambahkan pembatasan amunisi awal (30 peluru).
            b).Menampilkan jumlah peluru yang tersisa dalam magasin menggunakan fungsi         tampilAmunisi().
        4. Mekanisme Reload Peluru
            a). Jika amunisi habis, pemain harus menunggu reload selesai sebelum bisa menembak lagi.
            b). Menampilkan teks “RELOADING...” di layar saat reload berlangsung.

### Rahma Attaya Tamimah
1. Terdapat dua jenis musuh dengan tampilan dan perilaku yang berbeda.
2. Musuh dapat bergerak secara dinamis (naik-turun) untuk membuat pola serangan lebih sulit.
3. Musuh juga dapat menembakkan peluru ke arah pemain.
4. Jika peluru pemain mengenai musuh, musuh akan dihancurkan dan skor bertambah.

### Gema Adzan F - Bertanggung jawab dalam pembuatan menu utama, background, dan game state.
### A. Background
Membuat background bintang agar ambience luar angkasa dari game Space Invaders terasa.
### B. Menu Utama
Menu utama dari game Space Invaders yang terdiri dari 4 tombol, yaitu:
a). Play: Untuk memulai permainan.
b). About: Untuk menampilkan profil Kelompok C3.
c). Tutorial: Untuk menampilkan cara memainkan permainan.
d). Quit: Untuk keluar dari game.
### C. Game State
Game state yang berguna untuk memungkinkan user berada di menu utama, dalam game, dan lainnya.

### 5. Fairuz Sheva Muhammad - Bertanggung jawab dalam pengembangan gameplay seperti wave dan pengurangan skor.
    A. Membuat Sistem Wave
        a). Membuat sistem wave untuk memberikan tantangan kepada player, dengan sistem ketika semua musuh mati dalam wave tersebut, maka akan lanjut ke wave selanjutnya.
        b). Menampilkan juga wave yang sedang dihadapi.
    B. Membuat Sistem Pengurangan Skor
        a). Ketika musuh melewati batas/pemain, maka hal tersebut akan menyebabkan pengurangan skor.
        b). Pengurangan skor dibagi menjadi dua, untuk musuh biasa dan musuh besar.
