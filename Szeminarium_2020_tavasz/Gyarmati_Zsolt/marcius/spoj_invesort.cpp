#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define DEFS "abcdefghij"
#define MAXL (sizeof(DEFS)-1)

using namespace std;

/* Egy eleve lassú megoldásból megpróbáltam a lehető legtöbbet kihozni. */

unsigned char ketto[987654321+1];

inline unsigned int
permnum2(const char* p)
{
	unsigned int ff = 0;
	for(int i = 1; p[i]; i++){
		ff *= MAXL;
		ff += p[i] - 'a';
	}
	
	return ff;
}

inline unsigned int
permnum2table(const char* p, const char* tbl)
{
	unsigned int ff = 0;
	for(int i = 1; p[i]; i++){
		ff *= MAXL;
		ff += tbl[p[i] - 'a'] - 'a';
	}
	
	return ff;
}

inline void
reverse(string& str, int a, int b)
{
	while(a < b){
		swap(str[a], str[b]);
		a++;
		b--;
	}
}

inline char*
intcopy(const char* str, int a, int b)
{
	char* r = new char[11];
	r[10] = 0;
	int i = 0;
	for(; i < a; i++){
		r[i] = str[i];
	}
	for(; i <= b; i++){
		r[i] = str[b+a-i];
	}
	for(; i < MAXL; i++){
		r[i] = str[i];
	}
	return r;
}

const char* transmutation[45+1];

void
buildtable()
{
	const char* ixkde = DEFS;
	for(int i = 0, ole = 0; i < MAXL-1; i++){
		for(int j = i+1; j < MAXL; j++, ole++){
			transmutation[ole] = intcopy(ixkde, i, j);
		}
	}
}

inline void
tablecopy(char* dst, const char* src, const char* tbl)
{
	for(int i = 0; src[i]; i++){
		dst[i] = tbl[src[i] - 'a'];
	}
}

void
traverse()
{
	ketto[permnum2(DEFS)] = 1;
	queue<pair<const char*, unsigned int>> varolista;
	varolista.push({DEFS, permnum2(DEFS)});

	while(!varolista.empty()){
		auto most = varolista.front();
		varolista.pop();

		unsigned int lepes = ketto[most.second] + 1;

		for(int i = 0; i < 45; i++){
			unsigned int p = permnum2table(transmutation[i], most.first);
			if(!ketto[p]){
				ketto[p] = lepes;
				char* fos = new char[11];
				fos[10] = 0;
				tablecopy(fos, transmutation[i], most.first);
				varolista.push({fos, p});
			}else{
				if(ketto[p] > lepes){
					ketto[p] = lepes;
				}
			}
		}
	}
}

int
main()
{
	buildtable();
	traverse();

	char table[MAXL+1];
	char str1[MAXL+1], str2[MAXL+1];
	for(;;){
		scanf("%s %s", str1, str2);
		if(str1[0] == '*') break;

		for(int i = 0; i < MAXL; i++)
			table[str1[i] - 'a'] = i + 'a';

		for(int i = 0; i < MAXL; i++)
			str2[i] = table[str2[i] - 'a'];

		printf("%d\n", ketto[permnum2(str2)] - 1);
	};

	return 0;
}
