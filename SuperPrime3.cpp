//作业：大整数，比如9081321110693270343633073697474256143563558458718976746753830538032062222085722974121768604305613921745580037409259811952655310075487163797179490457039169594160088430571674960498834085812920457916453747019461644031395307920624947349951053530086146486307198155590763466429392673709525428510973272600608981219760099374675982933766845473509473676470788342281338779191792495900393751209539300628363443012 6538005862664913074813656220643842443844131905754565672075358391135537108795991638155474452610874309742867231360502542308382199053675592825240788613991898567277116881793749340807728335795394301261629479870548736450984003401594705923178314906195914825136973281314862289454100745237769034410057080703111299605127114594552921209928891515242515620324828055912854227507525717981351447473570262981491527798 
//重新设计下面的代码，使其可以处理大整数的素数与超级素数
//同时仔细理解面向对象的编程方式 
#include<iostream>
#include<string>
#define MAXTEST 20
using namespace std;
class BigInt {
	public:
		BigInt() {
		}
		BigInt(string num) {
			this->num.resize(num.size());
			for (int i = 0; i < num.length(); i++) {
				this->num[i] = num[i] - '0';
			}
		}
		BigInt(int len) {
			num.resize(num.size()+len);
			num.replace(0, len, len, 0);
		}
		~BigInt() {
		}
		friend BigInt operator- (BigInt a, int b);
		friend BigInt operator* (BigInt a, BigInt b);
		friend BigInt operator/ (BigInt a, BigInt b);
		friend BigInt operator% (BigInt a, BigInt b);


		
		string num;
	private:
		BigInt sub(BigInt a, BigInt b) {
			int lena = a.num.size(), lenb = b.num.size();
			BigInt c(lena);
			for (int i = 1; i <= lena; i++) {
				if (i <= lenb) {
					if (a.num[lena-i] < b.num[lenb-i]) {
						c.num[lena-i] = a.num[lena-i]+10-b.num[lenb-i];
						a.num[lena-i-1] -= 1;
					} else {
						c.num[lena-i] = a.num[lena-i]-b.num[lenb-i];
					}
				} else {
					c.num[lena-i] = a.num[lena-i];
				}
			}
			
			a.c_zero(c);
			return c;
		}
		int judge(BigInt &a, BigInt &b) {
			int lena = a.num.size(), lenb = b.num.size();
			if (lena > lenb) {
				return 1;
			} else if (lena < lenb) {
				return -1;
			} else {
				int i = 0;
				while ((a.num[i] == b.num[i]) && i < lena) {
					i += 1;
				}
				if (i == lena) {
					return 0;
				} else if (a.num[i] < b.num[i]) {
					return -1;
				} else if (a.num[i] > b.num[i]) {
					return 1;
				}
			}
		}
		void c_zero(BigInt &r) {
			for (int i = 0; i <= r.num.size(); i++) {
				if (r.num[i] != 0) {
				r.num.erase(0, i);
				break;
				}
			}
			return;
		}	
};
BigInt operator- (BigInt a, int b) {
	int len = a.num.length();
	while (a.num[len-1] == 0) {
		a.num[len-1] = 9;
		len -= 1;
	}
	a.num[len-1] -= 1;
	if (a.num[0] == 0) {
		a.num[0] = 9;
		a.num.resize(a.num.size()-1); 
	}
	return a;
}
BigInt operator* (BigInt a, BigInt b) {
	int lena, lenb, len;
	lena = a.num.size();
	lenb = b.num.size();
	len = lena + lenb;
	BigInt c(len);
	
	long long int array[len] = {0};
	for (int i = 1; i <= lena; i++) {
		for (int j = 1; j <= lenb; j++) {
			array[len-i-j+1] += (a.num[lena-i] * b.num[lenb-j]);
		}
	}
	
	for (int i = 1; i < len; i++) {
		array[len-i-1] += (array[len-i]/10);
		array[len-i] = (array[len-i] % 10);
	}
	for (int i = 0; i < len; i++) {
		c.num[i] = (char)array[i];
	}
	
	c.c_zero(c);
	 
	return c;
}
BigInt operator% (BigInt a, BigInt b) {
	BigInt fun(1), b1 = b;
	int i = 0, j = 0;
	int lena = a.num.size(), lenb = b.num.size(), len;
	
	switch (fun.judge(a, b)) {
		case -1: return a; break;
		case 0: return fun; break;
		case 1: len = lena-lenb; BigInt r(len+1); break;
	}
	len = lena-lenb;
	BigInt r(len+1);
	
	for (j = 0; j < len; j++) {
		b.num += (char) 0;
	}
	while (fun.judge(a, b1) > 0) {
		if (fun.judge(a, b) > 0) {
	  	a = fun.sub(a, b);
		}  else if (fun.judge(a, b) == 0) {
			return fun;
		} else if (fun.judge(a, b) < 0) {
			b.num.erase(b.num.end()-1);
			i += 1;
		}
	}
	if (fun.judge(a, b1) == 0) {
		return fun;
	} else if (fun.judge(a, b1) < 0) {
		return a;
	}
}
BigInt operator/ (BigInt a, BigInt b) {
	BigInt fun(1), b1 = b;
	int i = 0, j = 0;
	int lena = a.num.size(), lenb = b.num.size(), len;
	
	switch (fun.judge(a, b)) {
		case -1: return fun; break;
		case 0: fun.num[0] = 1; return fun; break;
		case 1: break;
	}
	len = lena-lenb;
	BigInt r(len+1);
	
	for (j = 0; j < len; j++) {
		b.num += (char) 0;
	}
	while (fun.judge(a, b1) > 0) {
		if (fun.judge(a, b) > 0) {
	  	a = fun.sub(a, b);
	  	r.num[i] += 1;
		}  else if (fun.judge(a, b) == 0) {
			r.num[i] += 1;
			fun.c_zero(r); 
			return r;
		} else if (fun.judge(a, b) < 0) {
			b.num.erase(b.num.end()-1);
			i += 1;
		}
	}
	if (fun.judge(a, b1) == 0) {
		r.num[len] += 1;
		fun.c_zero(r); 
		return r;
	} else if (fun.judge(a, b1) < 0) {
		fun.c_zero(r); 
		return r;
	}
}
class BigPrime : public BigInt{
public:
  BigPrime(string t) : BigInt(t){
  	n.num = this->num;
  }
  virtual bool isPrime() {
  	if (fm(n)) {
  		return true;
		}
		return false;
  }
private:
  BigInt n;
  BigInt fastpow(BigInt a, BigInt b, BigInt mod) {
  	BigInt r("1"), base = a, two("2");
  	while (b.num[0] != 0) {
  		int lenb;
  		lenb = b.num.size();
  		if (((int)b.num[lenb-1] % 2) != 0) {
  			r = r*base;
  			r = r%mod;
			}
			base = base*base;
			base = base%mod;
			b = b/two;
		}
		return r;
	}
	bool fm(BigInt x)	{
		BigInt tmp("30");
		for(int i = 2; i<=MAXTEST; ++i) {
			if (((fastpow(tmp,x-1,x)%x).num.size() != 1) || ((fastpow(tmp,x-1,x)%x).num[0] != 1))
				return false;
			tmp = tmp-1;
		}
		return true;
	}
	
}; 
class BigSuperPrime : public BigPrime {
public:
  BigSuperPrime(string t) : BigPrime(t){
  	int len = t.size(), i;
  	for (i = 0; i < len; i++) {
  		a[i] = t[i]-'0';
		}
		a[i] = -1;
  }
  virtual bool isPrime() {
  	BigPrime a(sum()), b(multi()), c(squaresum());
  	if (BigPrime::isPrime() && a.isPrime() && b.isPrime() && c.isPrime()) {
  		return true;
		}
    return false;
  }
private:
	int a[1005];
  string sum() {
  	int i = 0, sum = 0;
  	while (a[i] >= 0) {
  		sum += a[i];
  		i += 1;
		}
		char t[1005];
		sprintf(t, "%d", sum);
		string r = t;
		return r;
	}
	string multi() {
		BigInt multi(1);
		multi.num[0] = (char)1;
		int i = 0;
		while (a[i] >= 0) {
			BigInt tmp(1);
			tmp.num[0] = (char)a[i];
			multi = multi * tmp;
			i += 1;
		}
		return multi.num;
	}
	string squaresum() {
		int i = 0, squaresum = 0;
  	while (a[i] >= 0) {
  		squaresum += (a[i]*a[i]);
  		i += 1;
		}
		char t[1005];
		sprintf(t, "%d", squaresum);
		string r = t;
		return r;
	}
};
class Set {
public:
  Set(int sz);
  ~Set();
  bool add(BigPrime *bp);
  bool remove(BigPrime *bp);
  int count() const {
  	int ret = 0;
  	for (int i = 0; i < index; i++) {
  	  if (pset[i]->isPrime())
  	    ret += 1;
	  }
  	return ret;
  }
  int sum() const {
  	return 0;
  } 
private:
  BigPrime **pset;
  int size, index;
};
int main() {
  Set set(1000);
  BigSuperPrime bp("256432154654564132145464"), bp1("3564321354564697894658974564");
  set.add(&bp);
  set.add(&bp1);
  std::cout << set.count() << std::endl;
  return 0;
} 

Set::Set(int sz):size(sz) {
  index = 0;
  pset = new BigPrime*[size];  //分配存储空间 
}

Set::~Set() {
  delete[] pset;  //回收 
}
bool Set::add(BigPrime *bp) {
  pset[index++] = bp;
  return true;
}
