# Online Attendance System

Perangkat yang diberi nama “Online Attendance System” ini bekerja sesuai dengan namanya, menerima dan memproses absensi suatu instansi. Program terdiri dari dua mikrokontroler dan satu keypad yang berkerja bersamaan. Pengguna yang akan melakukan absen memberikan input sebuah kombinasi angka sesuai dengan ketentuan yang ada. Jika kombinasi angka yang dimasukkan valid dan sesuai dengan ketententuan, maka mesin akan meyalakan sebuah LED hijau dan mengirimkan sebuah email kepada satu penanggung jawab absen yang mengkonfirmasi bahwa pengguna telah absen. Jika kombinasi yang dimasukkan tidak sesuai, maka mesin akan menyalakan sebuah LED merah menandakan bahwa input dari pengguna tidak sesuai.

Proses identifikasi input yang terdaftar atau tidaknya dilakukan oleh microcontroller ATmega32. ATmega32 akan mengirimkan hasil identifikasi tersebut melalui komunikasi serial ke ESP8266. ESP8266 kemudian akan mengirimkan hasil identifikasi tersebut ke client dalam bentuk email. Supaya perangkat tersebut dapat mengirimkan email, kami menggunakan protokol SMTP dengan memanfaatkan API SMTP2Go. SMTP itu sendiri merupakan simple mail transfer protocol yang berfungsi untuk mengirimkan pesan agar tepat waktu dan efisien kepada penerima. SMTP memberi perintah untuk mengontrol negosiasi dan transmisi melalui koneksi data stream Transfer Control Protocol (TCP).

## Diagram Rangkaian
![Navigate](https://github.com/Razzaz/email_atmega32/raw/master/circuit_diagram.SVG)
