#ifndef LIBYZYL_RANDQUEUE_H
#define LIBYZYL_RANDQUEUE_H
#include<algorithm>
#include<vector>
#include<ctime>

#if __cplusplus >= 201103L
#include<random>
#include<chrono>
namespace YZYL{
	class rnd{
		private:
			std::random_device random_seed;
			std::mt19937 random_for_rand_queue_base;
		public:
			rnd(){
				random_for_rand_queue_base.seed(random_seed()^time(NULL)^
				std::chrono::system_clock::now().time_since_epoch().count()); 
			}
			unsigned int operator ()(){
				return random_for_rand_queue_base();
			}
			unsigned int operator ()(unsigned int r){
				return (long double)random_for_rand_queue_base()/
				(long double)random_for_rand_queue_base.max()*r+1e-6;
			}
			unsigned int operator ()(unsigned int l,unsigned int r){
				return (long double)random_for_rand_queue_base()/
				(long double)random_for_rand_queue_base.max()*r+1e-6+l;
			}
	};
}
#else
#warning This file provides better support \
for compilers and libraries for the \
ISO C++ 2011 standard. If possible, use the \
-std=c++11 or -std=gnu++11 compiler options.
#include<cstdlib>
namespace YZYL{
	class rnd{
		public:
			rnd(){
				srand(time(NULL));
			}
			unsigned int operator ()(){
				return rand()<<15|rand();
			}
			unsigned int operator ()(unsigned int r){
				return (long double)rand()/(long double)RAND_MAX*r+1e-6;
			}
			unsigned int operator ()(unsigned int l,unsigned int r){
				return (long double)rand()/(long double)RAND_MAX*r+1e-6+l;
			}
	};
}
#endif // C++11
namespace YZYL{
	template<typename _Tp,class rdcls=rnd>
	class rand_queue{
		private:
			std::vector<_Tp> rdqueue;
			rdcls rnds;
			template<typename _Tswap>
			void swap(_Tswap &a,_Tswap &b){
				_Tswap c=a;a=b;b=c;
			}
		public:
			typedef unsigned int size_t;
			void push(const _Tp &val){
				rdqueue.push_back(val);
				swap(rdqueue.at(rnds(rdqueue.size())),rdqueue.back());
			}
			_Tp pop(){
				swap(rdqueue.at(rnds(rdqueue.size())),rdqueue.back());
				_Tp _temp=rdqueue.back();
				rdqueue.pop_back();
				return _temp;
			}
			_Tp choice(){
				return rdqueue.at(rnds(rdqueue.size()));
			}
			size_t size(){
				return rdqueue.size();
			}
			bool empty(){
				return rdqueue.empty();
			}
#if __cplusplus >= 201103L
			void shuffle(){
				std::shuffle(rdqueue.begin(),rdqueue.end());
			}
#endif
	};
} // namespace YZYL
#endif // LIBYZYL_RANDQUEUE_H
