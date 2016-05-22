insert into cities (name) values ('İstanbul');
insert into cities (name) values ('Antalya');
insert into cities (name) values ('Ankara');
insert into cities (name) values ('İzmir');
insert into cities (name) values ('Trabzon');
insert into cities (name) values ('Giresun');
insert into cities (name) values ('Kayseri');
insert into cities (name) values ('Şanlıurfa');
insert into cities (name) values ('Van');

insert into customers(tc, name, surname, phone, city_id, address) values('32706318316', 'Taha İbrahim', 'Bayram', '543 936 11 45', 1, 'Beyaz Kupa Mahallesi. Akdenizçayı Sokak: Arnavutköy, İstanbul');
insert into customers(tc, name, surname, phone, city_id, address) values('54339236634', 'Regaip Ergenekon', 'Yiğit', '535 223 34 44', 2, 'Steve Jobs Mahallesi, Merkez, Antalya');
insert into customers(tc, name, surname, phone, city_id, address) values('23443118713', 'Burak Emre', 'Ayyıldız', '553 344 30 33', 5, 'Fatih Mahallesi Elma Sokak No:3');
insert into customers(tc, name, surname, phone, city_id, address) values('54339236634', 'Mehmet Hakan', 'Özdener', '544 433 23 25', 4, 'Neşet Ertaş Mahallesi. Müslüm Sokak: No: 5 ');

insert into offices(name, city_id, address) values('Değirmendere', 5, 'Değirmendere mahallesi, Trabzon');
insert into offices(name, city_id, address) values('Arnavutköy Merkez', 1, 'Arnavutköy merkez, İstanbul');
insert into offices(name, city_id, address) values('Beşiktaş', 1, 'Beşiktaş, İstanbul');
insert into offices(name, city_id, address) values('Taksim', 1, 'Taksim, İstanbul');
insert into offices(name, city_id, address) values('Akçabat', 1, 'Akçabat, Trabzon');

insert into shipments(length, width, height, weight, sending_customer_id, receiving_customer_id, payment_type, amount, status, sending_office_id, receiving_office_id) values(23, 12, 30, 3, 1, 2, 1, 7.5, "Dağıtıma çıkarıldı.", 1, 2);
insert into shipments(length, width, height, weight, sending_customer_id, receiving_customer_id, payment_type, amount, status, sending_office_id, receiving_office_id) values(25, 22, 11, 5, 3, 2, 1, 8.4, "Teslim edildi.", 2, 1);	
insert into shipments(length, width, height, weight, sending_customer_id, receiving_customer_id, payment_type, amount, status, sending_office_id, receiving_office_id) values(51, 12, 11, 6, 4, 1, 1, 7.4, "Hazırlanıyor.", 1, 4);	
