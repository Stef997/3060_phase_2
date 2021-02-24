CC=g++

all: account/account.cpp bankTransaction/bankTransaction.cpp deposit/deposit.cpp login.cpp paybill/paybill.cpp transfer/transfer.cpp user/user.cpp bankSession/bankSession.cpp ChangePlan/changePlan.cpp main.cpp transaction/transaction.cpp transfer.cpp withdrawal/withdrawal.cpp
	g++ account/account.cpp bankTransaction/bankTransaction.cpp deposit/deposit.cpp login.cpp paybill/paybill.cpp transfer/transfer.cpp user/user.cpp bankSession/bankSession.cpp ChangePlan/changePlan.cpp main.cpp transaction/transaction.cpp transfer.cpp withdrawal/withdrawal.cpp -o test
