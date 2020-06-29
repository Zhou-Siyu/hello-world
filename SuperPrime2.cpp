//作业：删除多余的集合类，使用继承方法实现相同的功能。 
#include <iostream>
class Prime {
  public:
  	Prime():number(0) {
	}
  	Prime(int n):number(n) {
	}
	~Prime() {
	}
  virtual bool isPrime() { 
  	if (number == 1 || number == 0)
			return false;
	  for (int i = 2; i*i <= number; i++) {
	  	if (number%i == 0) {
	  		return false;
			}
		}
		return true; 
	} 
  private:
  	const int number;
}; 
class PrimeSet {
  public:
  	PrimeSet(int size) {
  	  //集合的构造什么？ 
  	  set = new Prime*[3];
  	  pset = new Prime*[size];
  	  this->size = size;
  	  index = 0;
  	  pindex = 0;
	}
	~PrimeSet() {
  	for (int i = 0; i < 3; ++i)  //销毁对象 
			delete set[i]; 
	  delete[] set;
	  
	  for (int i = 0; i < index; ++i)  //销毁对象 
			delete pset[i]; 
	  delete[] pset;
	}
 	int count() {
  	int count = 0;
  	for (int i = 0; i < size; i++)
      if(pset[i]->isPrime())
 	      count += 1;
	  return count; 
	}

	void add(int n) {
	  Prime *p = new Prime(n);
	  set[index] = p;
	  index += 1;
	}
	
	bool add(Prime *p) {
		if(pindex == size)  return false;
	  pset[pindex] = p;
	  pindex += 1;
	  return true;
	}
	
	bool isAllPrime() {
	  for(int i = 0; i < index; i++)
	    if (!set[i]->isPrime())
	      return false;
	  return true;
	} 
  private:
  	Prime **set, **pset;
		int size, index, pindex;
};
class SuperPrime : public Prime {
  public:
  	SuperPrime():Prime(0), pset(3) {
  	}
  	SuperPrime(int n):Prime(n), pset(3) {
	  // number split into N
	  	int i = 0;
			int temp = n;
		 	while(temp > 0) {
	  		int t = temp % 10;
			  temp /= 10;
		  	A[i++] = t;  //作业：单个数字为对象？还是和/积/平方和为对象？
			}
			A[i] = -1;
			sum();
			multi();
			squareSum();
			pset.add(n);
		}
  	~SuperPrime() {
		}
  	virtual bool isPrime() {
	  	if (Prime::isPrime() && pset.isAllPrime())
	    	return true; 
  		return false;
		}
  private:
  	int A[100];
  	PrimeSet pset;
		int sum() {
			int n = 0, i = 0;
			while(A[i] >= 0) {
				n += A[i++];
			}
			pset.add(n);
		  return 0;
		}
		int multi() {
			int n = 1, i = 0;
			while(A[i] >= 0) {
				n *= A[i++];
			}
			pset.add(n);
		  return 0;
		}
		int squareSum() {
			int n = 0, i = 0;
			while(A[i] >= 0) {
				n += A[i]*A[i];
				i++;
			}
			pset.add(n);
		  return 0;
		}
};
int main() {
  SuperPrime sp(113);
  SuperPrime sp1(131);
  PrimeSet set(2);
  set.add(&sp);
  set.add(&sp1);
  std::cout << "How many:" << set.count() << std::endl;

  return 0;
}
