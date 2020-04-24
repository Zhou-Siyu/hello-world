//��ҵ���������������¿�ܵĴ���ϸ�ڣ������ܱ������еõ���ȷ��� 
#include <iostream>
//�ж�һ�����Ƿ�Ϊ���� 
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
//�ж�N��Ԫ���Ƿ�Ϊ���� 
class PrimeSet{
  public:
  	PrimeSet(int size) {
  	  //���ϵĹ���ʲô�� 
  	  N = new Prime*[size];
//  	  this->size = size;
  	  index = 0;
	}
	~PrimeSet() {
  	for (int i = 0; i < index; ++i)  //���ٶ��� 
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
//��һ�����ĸ�λ���ְ�Ҫ����ϣ�������N������ж��Ƿ�Ϊ�������� 
class SuperPrime : public Prime{
  public:
  	SuperPrime():Prime(0), pset(4) {  //Ϊʲô�����У� 
  	}
  	SuperPrime(int n):Prime(n), pset(4) {
			// number split into A
			int i = 0;
			int temp = n;
		 	while(temp > 0) {
	  		int t = temp % 10;
			  temp /= 10;
		  	A[i++] = t;  //��ҵ����������Ϊ���󣿻��Ǻ�/��/ƽ����Ϊ����
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
  	  //��ôʹ��pset�� 
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
//��Χ�ڳ��������ĸ��������ǵĺ� 
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
