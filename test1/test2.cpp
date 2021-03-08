#include <iostream>
#include <string>
#include <fstream>
#include <io.h> 

using namespace std;


 int CutTimestame(int pos, int n, const string& str)
{
	string Type = str.substr(pos,n);
	string t = "timestame:";
	return strcmp(Type.c_str(), t.c_str()); // 0 1 -1


}

static int CutNumpart(int n, int pos, const string& str)
{
	string Type = str.substr(pos, n);
	for (int i = 0; i<Type.size(); i++)
	{

		if ((Type.at(i) > '9') || (Type.at(i) < '0') && (Type.at(i) != '.'))
		{
			return -1;
		}
	}
	return 0;

}

static int Commapart( const string& str)
{
	return str.find(",");
}

int Cutobjid(int pos, int n, const string& str)
{
	string Type = str.substr(pos, n);
	string t = ",objid:";
	return strcmp(Type.c_str(), t.c_str()); // 0 1 -1


}


int Cuttype(int pos, int n, const string& str)
{
	string Type = str.substr(pos, n);
	string t = ",type:";
	return strcmp(Type.c_str(), t.c_str()); // 0 1 -1


}

int Cutxpos(int pos, int n, const string& str)
{
	string Type = str.substr(pos, n);
	string t = ",xpos:";
	return strcmp(Type.c_str(), t.c_str()); // 0 1 -1


}

int Cutxspeed(int pos, int n, const string& str)
{
	string Type = str.substr(pos, n);
	string t = ",xspeed:";
return strcmp(Type.c_str(), t.c_str()); // 0 1 -1


}


int Cutyspeed(int pos, int n, const string& str)
{
	string Type = str.substr(pos, n);
	string t = ",yspeed:";
	return strcmp(Type.c_str(), t.c_str()); // 0 1 -1


}

int Cutangle(int pos, int n, const string& str)
{
	string Type = str.substr(pos, n);
	string t = ",angle:";
	return strcmp(Type.c_str(), t.c_str()); // 0 1 -1


}


int Cutdistense(int pos, int n, const string& str)
{
	string Type = str.substr(pos, n);
	string t = ",distense:";
	return strcmp(Type.c_str(), t.c_str()); // 0 1 -1


}

int Cutrcs(int pos, int n, const string& str)
{
	string Type = str.substr(pos, n);
	string t = ",rcs:";
	return strcmp(Type.c_str(), t.c_str()); // 0 1 -1


}

static string CutNewstring(int pos, const string& str)
{
	return str.substr(pos);
}

void GetLineAndPrint(string in_name)
{
	ifstream fin(in_name);
	if (!fin)
	{
		cerr << "open file error" << endl;
		exit(-1);
	}
	int linecnt = 0;
	string str;
	while (getline(fin, str))
	{
		//cout << str << endl;
		//cout << str << "\n";
		++linecnt;

		//string str = "timestame:1614782140.157000000,objid:1,type:0,xpos:0.000000ypos:0.000000,xspeed:0.010000,yspeed:0.130000,angle:-0.300000,distense:75.200000,rcs:15.000000";
		//cout << CutTimestame(0, 10, str);
		int i = 0;
		int pos = Commapart(str);
		//cout << Cutobjid(pos, 7, str);

		string str2 = CutNewstring(pos + 1, str);
		int pos2 = Commapart(str2);
		//cout << Cuttype(pos2, 6, str2);

		string str3 = CutNewstring(pos2 + 1, str2);
		int pos3 = Commapart(str3);
		//cout << Cutxpos(pos3, 6, str3);

		string str4 = CutNewstring(pos3 + 1, str3);
		int pos4 = Commapart(str4);
		//cout << Cutxspeed(pos4, 8, str4);

		string str5 = CutNewstring(pos4 + 1, str4);
		int pos5 = Commapart(str5);
		//cout << Cutyspeed(pos5, 8, str5);


		string str6 = CutNewstring(pos5 + 1, str5);
		int pos6 = Commapart(str6);
		//cout << Cutangle(pos6, 7, str6);

		string str7 = CutNewstring(pos6 + 1, str6);
		int pos7 = Commapart(str7);
		//cout << Cutdistense(pos7, 10, str7);

		string str8 = CutNewstring(pos7 + 1, str7);
		int pos8 = Commapart(str8);
		//cout << Cutrcs(pos8, 5, str8) << "\n";


		if ((CutTimestame(0, 10, str) + Cutobjid(pos, 7, str) + Cuttype(pos2, 6, str2) + Cutxpos(pos3, 6, str3) + Cutxspeed(pos4, 8, str4) + Cutyspeed(pos5, 8, str5) + Cutangle(pos6, 7, str6) + Cutdistense(pos7, 10, str7) + Cutrcs(pos8, 5, str8)) != 0)
		{

			cout << "数据出错文档是："<< in_name <<"数据出错行数为：" << linecnt << endl;
		}
	}
}


//int main()
//{
//
//
//
//
//
//
//	string label_file = "G:/毫米波/radar/radar_1_1614782139847000000.txt";
//	ifstream labels(label_file.c_str());
//
//	if (!labels.is_open()) {
//		cout << "Can't open the label file!" << endl;
//		return -1;
//	}
//
//	ofstream file("linecnt.txt");
//	int linecnt = 0;
//	string str;
//	while (getline(labels, str))
//	{
//		//cout << str << "\n";
//		++linecnt;
//		
//		//string str = "timestame:1614782140.157000000,objid:1,type:0,xpos:0.000000ypos:0.000000,xspeed:0.010000,yspeed:0.130000,angle:-0.300000,distense:75.200000,rcs:15.000000";
//		//cout << CutTimestame(0, 10, str);
//		int i = 0;
//		int pos = Commapart(str);
//		//cout << Cutobjid(pos, 7, str);
//
//		string str2 = CutNewstring(pos + 1, str);
//		int pos2 = Commapart(str2);
//		//cout << Cuttype(pos2, 6, str2);
//
//		string str3 = CutNewstring(pos2 + 1, str2);
//		int pos3 = Commapart(str3);
//		//cout << Cutxpos(pos3, 6, str3);
//
//		string str4 = CutNewstring(pos3 + 1, str3);
//		int pos4 = Commapart(str4);
//		//cout << Cutxspeed(pos4, 8, str4);
//
//		string str5 = CutNewstring(pos4 + 1, str4);
//		int pos5 = Commapart(str5);
//		//cout << Cutyspeed(pos5, 8, str5);
//
//
//		string str6 = CutNewstring(pos5 + 1, str5);
//		int pos6 = Commapart(str6);
//		//cout << Cutangle(pos6, 7, str6);
//
//		string str7 = CutNewstring(pos6 + 1, str6);
//		int pos7 = Commapart(str7);
//		//cout << Cutdistense(pos7, 10, str7);
//
//		string str8 = CutNewstring(pos7 + 1, str7);
//		int pos8 = Commapart(str8);
//		//cout << Cutrcs(pos8, 5, str8) << "\n";
//
//
//		if((CutTimestame(0, 10, str) + Cutobjid(pos, 7, str) + Cuttype(pos2, 6, str2) + Cutxpos(pos3, 6, str3) + Cutxspeed(pos4, 8, str4) + Cutyspeed(pos5, 8, str5) + Cutangle(pos6, 7, str6) + Cutdistense(pos7, 10, str7) + Cutrcs(pos8, 5, str8)) != 0 )
//		{
//			
//			cout << "数据出错行数为：" << linecnt << endl;
//			file << "出错的行数为：" << linecnt << "\n";
//		}
//	}
//	file.close();
//}


int main()
{
	struct _finddata_t fileinfo;
	string in_name;
	string in_path = "G:/毫米波/radar";
	string curr = "G:/毫米波/radar/*.txt";
	long handle;
	if ((handle = _findfirst(curr.c_str(), &fileinfo)) == -1L)
	{
		cout << "没有找到匹配文件!" << endl;
		return 0;
	}
	else
	{
		in_name = in_path + "\\" + fileinfo.name;
		GetLineAndPrint(in_name);
		while (!(_findnext(handle, &fileinfo)))
		{
			in_name = in_path + "\\" + fileinfo.name;
			GetLineAndPrint(in_name);
		}
		_findclose(handle);
	}
}