//作业：面向对象设计以下框架的代码细节，程序能编译运行得到正确结果 
#include <iostream>
//判断一个数是否为素数 
class Prime {
  public:
  	Prime():number(0) {
	}
  	Prime(int n):number(n) {
	}
	~Prime() {
	}
  	bool isPrime() { 
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
//判断N中元素是否都为素数 
class PrimeSet{
  public:
  	PrimeSet(int size) {
  	  //集合的构造什么？ 
  	  N = new Prime*[size];
//  	  this->size = size;
  	  index = 0;
	}
	~PrimeSet() {
  	for (int i = 0; i < index; ++i)  //销毁对象 
			delete N[i]; 
	  delete[] N;
	}
	bool add(int n) { 
//	  if(index == size)  return false;
	  Prime *p = new Prime(n);
	  N[index] = p;
	  index += 1;
	  return true;
	}
	bool isAllPrime() {
	  for(int i = 0; i < index; i++)
	    if (!N[i]->isPrime())
	      return false;
	  return true;
	} 
  private:
  	Prime **N;
		int size, index;
};
//将一个数的各位数字按要求组合，并传入N，最后判断是否为超级素数 
class SuperPrime : public Prime{
  public:
  	SuperPrime():Prime(0), pset(4) {  //为什么必须有？ 
  	}
  	SuperPrime(int n):Prime(n), pset(4) {
			// number split into A
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
  	bool isSuperPrime() {
  	  //怎么使用pset？ 
  	  /*Prime p(number);
	  	if (p.isPrime())
		    return true; 
	  	return false;*/
	  	if (pset.isAllPrime())
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
//求范围内超级素数的个数及它们的和 
class SuperPrimeSet {
	public:
		SuperPrimeSet(int from, int to) {
		  size = to - from + 1;
		  this->from = from;
		  for (int i = from; i <= to; i++)
		    set[i - from] = new SuperPrime(i);
		}
		~SuperPrimeSet() {
		  for(int i = 0; i < size; i++)
		    delete set[i];
		}
		int count() {
		  int count = 0;
		  for (int i = 0; i < size; i++)
		    if(set[i]->isSuperPrime())
		      count += 1;
	  	return count; 
		}
		int sum() {
		  int sum = 0;
		  for (int i = 0; i < size; i++)
		    if(set[i]->isSuperPrime())
		      sum += i+from;
		  return sum; 
		}
	private:
		SuperPrime *set[9999];
		int size, from;
};
int main() {
  SuperPrime sp(113);
  if (sp.isSuperPrime())
    std::cout << "113 is SuperPrime" << std::endl;
  else
    std::cout << "113 is NOT SuperPrime" << std::endl;
    
  SuperPrimeSet ss(100, 999);
  std::cout << "count:" << ss.count() << std::endl;
  std::cout << "sum:" << ss.sum() <<  std::endl;
  return 0;
}
