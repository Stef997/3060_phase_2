CC=g++

all: main.cpp account/account.cpp transaction/transaction.cpp login/login.cpp user/user.cpp session/session.cpp main.cpp transaction/transaction.cpp user/adminUser.cpp user/standardUser.cpp deposit/deposit.cpp withdrawal/withdrawal.cpp paybill/paybill.cpp transfer/transfer.cpp
	g++ main.cpp session/session.cpp transaction/transaction.cpp user/user.cpp login/login.cpp account/account.cpp user/adminUser.cpp user/standardUser.cpp deposit/deposit.cpp withdrawal/withdrawal.cpp paybill/paybill.cpp transfer/transfer.cpp -o test
