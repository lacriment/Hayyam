CREATE TABLE IF NOT EXISTS cities (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	name TEXT
);

CREATE TABLE IF NOT EXISTS customers (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	tc TEXT,
	name TEXT,
	surname TEXT,
	phone TEXT,
	city_id INTEGER,
	address TEXT
);

CREATE TABLE IF NOT EXISTS distances (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	first_office_id INTEGER,
	second_office_id INTEGER,
	value REAL
);

CREATE TABLE IF NOT EXISTS offices (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	name TEXT,
	city_id INTEGER,
	address TEXT
);

CREATE TABLE IF NOT EXISTS shipments (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	length INTEGER,
	width INTEGER,
	height INTEGER,
	weight INTEGER,
	sending_customer_id INTEGER,
	receiving_customer_id INTEGER,
	payment_type INTEGER,
	amount REAL,
	status INT,
	sending_office_id INTEGER,
	receiving_office_id INTEGER
);