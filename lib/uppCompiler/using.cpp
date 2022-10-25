#include<bits/stdc++.h>
using namespace std;
string argvs="g++ .tempCompilingFile114514/temp2.cpp -o ",inf;
const char * const lib=
"#include<bits/stdc++.h>\n\
using namespace std;\n\
#define le (\n\
#define ri )\n\
#define Le [\n\
#define Ri ]\n\
#define LE {\n\
#define RI }\n\
#define lE <\n\
#define rI >\n\
#define mt >  //more than\n\
#define lt <  //less than\n\
#define nm <= //not more than\n\
#define nl >= //not less than\n\
#define eq == //equal\n\
#define ne != //not equal\n\
#define AN && //and\n\
#define OR || //or\n\
#define NO !  //not\n\
#define pl +  //plus\n\
#define mn -  //minus\n\
#define ti *  //times\n\
#define di /  //divided by\n\
#define mo %  //mod\n\
#define An &  //and\n\
#define Or |  //or\n\
#define xo ^  //xor\n\
#define No ~  //not\n\
#define ml << //move to left\n\
#define mr >> //move to right\n\
#define ed ;  //end\n\
#define wi ,  //with\n\
#define gt =  //get\n\
#define sa ++ //self addition\n\
#define sd -- //self decrement\n\
#define ie int       //integer\n\
#define bi long long //big integer\n\
#define un unsigned\n\
#define ch char\n\
#define vo void\n\
#define db double\n\
#define co const\n\
#define ve vector\n\
#define mp map\n\
#define pq priority_queue\n\
#define qu queue\n\
#define st stack\n\
#define sr string\n\
#define ma main\n\
#define fo freopen\n\
#define si stdin\n\
#define so stdout\n\
#define el else\n\
#define rt return\n\
#define gc getchar\n\
#define pc putchar\n\
#define il inline\n\
#define fr for\n\
#define wh while\n\
il ie rd le ri LE\n\
    ie x ed ch c ed\n\
    wh le le c gt gc le ri ri lt '0' OR c mt '9' ri ed\n\
    x gt c mn '0' ed\n\
    wh le le c gt gc le ri ri nl '0' AN c nm '9' ri\n\
        x gt x ti 10 mn '0' pl c ed\n\
    rt x ed\n\
RI\n\
il vo wt le ie x ri LE\n\
    if le x mt 9 ri wt le x di 10 ri ed\n\
    pc le x mo 10 pl 48 ri ed\n\
RI\n\
// made by using\n";


int main(int argc,char **argv){
	if(argc<2){
		printf("Usage: using <Filename> [...]\nFilename must end with `.upp'\n");
		return 1;
	}
	static char cmd[4096];
	sprintf(cmd,"mkdir .tempCompilingFile114514 && cp %s .tempCompilingFile114514/temp.cpp",argv[1]);
	if(system(cmd)){
		system("rm -r ./.tempCompilingFile114514");
		printf("File Error!\n");
		return 1;
	} 
	ofstream fgo(".tempCompilingFile114514/temp2.cpp");
	ifstream in(".tempCompilingFile114514/temp.cpp");
	fgo<<lib;
	while(getline(in,inf)){
		fgo<<inf<<endl;
	}
	in.close();fgo.close();
	int k=strlen(argv[1])-1;
	while(k>0&&argv[1][k]!='.') argv[1][k--]=0;
	argv[1][k]=0;
	argvs+=argv[1];
	// printf(argv[1]);
	argvs+=' ';
	for(int i=2;i<argc;i++){
		argvs+=argv[i];
		argvs+=' ';
	}
	argvs+="2> .compiling.log";
	// printf(argvs.c_str());
	if(system(argvs.c_str())){
		system("rm -r ./.tempCompilingFile114514");
		printf("Compiling Error!\n");
		return 1;
	}
	system("rm .compiling.log");
	system("rm -r ./.tempCompilingFile114514");
	return 0;
}
