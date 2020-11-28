#include"type.h"

bool isAnsi(wchar_t c) {
	if (c >= 1 and c <= 127 or c >= 913 and c <= 929 or c >= 931 and c <= 937 or c >= 945 and c <= 961 or c >= 963 and c <= 969 or c >= 1040 and c <= 1103 or c >= 8544 and c <= 8555 or c >= 8560 and c <= 8569 or c >= 9312 and c <= 9321 or c >= 9332 and c <= 9371 or c >= 9472 and c <= 9547 or c >= 9552 and c <= 9587 or c >= 9601 and c <= 9615 or c >= 12293 and c <= 12311 or c >= 12321 and c <= 12329 or c >= 12353 and c <= 12435 or c >= 12449 and c <= 12534 or c >= 12549 and c <= 12585 or c >= 12832 and c <= 12841 or c >= 19968 and c <= 40869 or c >= 57344 and c <= 59492 or c >= 65075 and c <= 65092 or c >= 65097 and c <= 65106 or c >= 65113 and c <= 65126 or c >= 65281 and c <= 65374) {
		return true;
	}
	const wchar_t a[] = { 164, 167, 168, 176, 177, 183, 215, 224, 225, 232, 233, 234, 236, 237, 242, 243, 247, 249, 250, 252, 257, 275, 283, 299, 324, 328, 333, 363, 462, 464, 466, 468, 470, 472, 474, 476, 593, 609, 711, 713, 714, 715, 729, 913, 914, 915, 916, 917, 918, 919, 920, 921, 922, 923, 924, 925, 926, 927, 928, 929, 931, 932, 933, 934, 935, 936, 937, 945, 946, 947, 948, 949, 950, 951, 952, 953, 954, 955, 956, 957, 958, 959, 960, 961, 963, 964, 965, 966, 967, 968, 969, 1025, 1040, 1041, 1042, 1043, 1044, 1045, 1046, 1047, 1048, 1049, 1050, 1051, 1052, 1053, 1054, 1055, 1056, 1057, 1058, 1059, 1060, 1061, 1062, 1063, 1064, 1065, 1066, 1067, 1068, 1069, 1070, 1071, 1072, 1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087, 1088, 1089, 1090, 1091, 1092, 1093, 1094, 1095, 1096, 1097, 1098, 1099, 1100, 1101, 1102, 1103, 1105, 8208, 8212, 8213, 8214, 8216, 8217, 8220, 8221, 8230, 8240, 8242, 8243, 8245, 8251, 8364, 8451, 8453, 8457, 8470, 8481, 8544, 8545, 8546, 8547, 8548, 8549, 8550, 8551, 8552, 8553, 8554, 8555, 8560, 8561, 8562, 8563, 8564, 8565, 8566, 8567, 8568, 8569, 8592, 8593, 8594, 8595, 8599, 8600, 8601, 8712, 8719, 8721, 8725, 8730, 8733, 8734, 8735, 8736, 8739, 8741, 8743, 8744, 8745, 8746, 8747, 8750, 8756, 8757, 8758, 8759, 8765, 8776, 8780, 8786, 8800, 8801, 8804, 8805, 8806, 8807, 8814, 8815, 8853, 8857, 8869, 8895, 8978, 9312, 9313, 9314, 9315, 9316, 9317, 9318, 9319, 9320, 9321, 9332, 9333, 9334, 9335, 9336, 9337, 9338, 9339, 9340, 9341, 9342, 9343, 9344, 9345, 9346, 9347, 9348, 9349, 9350, 9351, 9352, 9353, 9354, 9355, 9356, 9357, 9358, 9359, 9360, 9361, 9362, 9363, 9364, 9365, 9366, 9367, 9368, 9369, 9370, 9371, 9472, 9473, 9474, 9475, 9476, 9477, 9478, 9479, 9480, 9481, 9482, 9483, 9484, 9485, 9486, 9487, 9488, 9489, 9490, 9491, 9492, 9493, 9494, 9495, 9496, 9497, 9498, 9499, 9500, 9501, 9502, 9503, 9504, 9505, 9506, 9507, 9508, 9509, 9510, 9511, 9512, 9513, 9514, 9515, 9516, 9517, 9518, 9519, 9520, 9521, 9522, 9523, 9524, 9525, 9526, 9527, 9528, 9529, 9530, 9531, 9532, 9533, 9534, 9535, 9536, 9537, 9538, 9539, 9540, 9541, 9542, 9543, 9544, 9545, 9546, 9547, 9620, 9621, 9632, 9633, 9650, 9651, 9661, 9670, 9671, 9675, 9678, 9679, 9699, 9700, 9701, 9733, 9734, 9737, 9792, 9794, 12289, 12290, 12291, 12293, 12296, 12297, 12298, 12299, 12300, 12301, 12302, 12303, 12304, 12305, 12307, 12308, 12309, 12310, 12311, 12318, 12353, 12354, 12355, 12356, 12357, 12358, 12359, 12360, 12361, 12362, 12363, 12364, 12365, 12366, 12367, 12368, 12369, 12370, 12371, 12372, 12373, 12374, 12375, 12376, 12377, 12378, 12379, 12380, 12381, 12382, 12383, 12384, 12385, 12386, 12387, 12388, 12389, 12390, 12391, 12392, 12393, 12394, 12395, 12396, 12397, 12398, 12399, 12400, 12401, 12402, 12403, 12404, 12405, 12406, 12407, 12408, 12409, 12410, 12411, 12412, 12413, 12414, 12415, 12416, 12417, 12418, 12419, 12420, 12421, 12422, 12423, 12424, 12425, 12426, 12427, 12428, 12429, 12430, 12431, 12432, 12433, 12434, 12435, 12444, 12445, 12446, 12449, 12450, 12451, 12452, 12453, 12454, 12455, 12456, 12457, 12458, 12459, 12460, 12461, 12462, 12463, 12464, 12465, 12466, 12467, 12468, 12469, 12470, 12471, 12472, 12473, 12474, 12475, 12476, 12477, 12478, 12479, 12480, 12481, 12482, 12483, 12484, 12485, 12486, 12487, 12488, 12489, 12490, 12491, 12492, 12493, 12494, 12495, 12496, 12497, 12498, 12499, 12500, 12501, 12502, 12503, 12504, 12505, 12506, 12507, 12508, 12509, 12510, 12511, 12512, 12513, 12514, 12515, 12516, 12517, 12518, 12519, 12520, 12521, 12522, 12523, 12524, 12525, 12526, 12527, 12528, 12529, 12530, 12531, 12532, 12533, 12534, 12541, 12542, 12549, 12550, 12551, 12552, 12553, 12554, 12555, 12556, 12557, 12558, 12559, 12560, 12561, 12562, 12563, 12564, 12565, 12566, 12567, 12568, 12569, 12570, 12571, 12572, 12573, 12574, 12575, 12576, 12577, 12578, 12579, 12580, 12581, 12582, 12583, 12584, 12585, 12832, 12833, 12834, 12835, 12836, 12837, 12838, 12839, 12840, 12841, 12849, 12963, 13199, 13213, 13214, 13217, 13252, 13262, 13266, 13269, 59190, 59191, 59226, 59227, 59228, 59335, 59336, 63733, 63788, 63865, 63893, 63975, 63985, 64013, 64014, 64015, 64017, 64020, 64024, 64032, 64033, 64036, 64040, 64041, 65073, 65075, 65076, 65077, 65078, 65079, 65080, 65081, 65082, 65083, 65084, 65085, 65086, 65087, 65088, 65089, 65090, 65091, 65092, 65109, 65110, 65111, 65129, 65130, 65131, 65281, 65282, 65283, 65284, 65285, 65286, 65287, 65288, 65289, 65290, 65291, 65292, 65293, 65294, 65295, 65296, 65297, 65298, 65299, 65300, 65301, 65302, 65303, 65304, 65305, 65306, 65307, 65308, 65309, 65310, 65311, 65312, 65313, 65314, 65315, 65316, 65317, 65318, 65319, 65320, 65321, 65322, 65323, 65324, 65325, 65326, 65327, 65328, 65329, 65330, 65331, 65332, 65333, 65334, 65335, 65336, 65337, 65338, 65339, 65340, 65341, 65342, 65343, 65344, 65345, 65346, 65347, 65348, 65349, 65350, 65351, 65352, 65353, 65354, 65355, 65356, 65357, 65358, 65359, 65360, 65361, 65362, 65363, 65364, 65365, 65366, 65367, 65368, 65369, 65370, 65371, 65372, 65373, 65374, 65504, 65505, 65507, 65509 };
	for (int i = 0; i < 788; i++) {
		if (c == a[i])return true;
	}
	return false;
}

wstring a2h(const wchar_t* ascii)
{
	wstring s(L"");
	wchar_t chHex[] = L"0123456789ABCDEF";
	int len = WideCharToMultiByte(CP_UTF8, 0, ascii, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, ascii, -1, str, len, NULL, NULL);
	for (auto i = 0; i < len - 1; i++) {
		s += chHex[(unsigned char)str[i] >> 4];
		s += chHex[(unsigned char)str[i] & 0xf];
	}
	return L"[emoji=" + s + L"]";
}

const wchar_t* h2a(wstring hex)
{
	string s("");
	for (auto i = hex.begin() + 7; i < hex.end() - 1; i += 2) {
		*i = *i > 60 ? *i - 55 : *i - 48;
		*(i + 1) = *(i + 1) > 60 ? *(i + 1) - 55 : *(i + 1) - 48;
		char c = (*i << 4) + *(i + 1);
		s += c;
	}
	const char* str = s.c_str();
	int len = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, str, -1, wstr, len);
	return wstr;
}

wstring s2u(string str) {
	const char* cstr = str.c_str();
	int len = MultiByteToWideChar(CP_UTF8, 0, cstr, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, cstr, -1, wstr, len);
	std::wstring s(wstr);
	return s;
}

string u2s(wstring str) {
	const wchar_t* tstr = str.c_str();
	int len = WideCharToMultiByte(CP_UTF8, 0, tstr, -1, NULL, 0, NULL, NULL);
	char* cstr = new char[len + 1];
	memset(cstr, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, tstr, -1, cstr, len, NULL, NULL);
	string s(cstr);
	return s;
}

wstring eec(wstring str) {
	std::wstring s(L""), st(L"");
	for (auto i = str.begin(); i < str.end(); i++) {
		if (isAnsi(*i)) {
			if (st != L"") {
				s += a2h(st.c_str());
				st = L"";
			}
			s += *i;
		}
		else {
			st += *i;
		}
	}
	if (st != L"") {
		s += a2h(st.c_str());
		st = L"";
	}
	return s;
}

wstring edc(wstring str) {
	wstring s(L""), st(str);
	int pos, p;
	while ((pos = st.find(L"[emoji=")) != str.npos) {
		s += st.substr(0, pos);
		p = st.find(L"]", pos) + 1;
		s += h2a(st.substr(pos, p - pos));
		st = st.substr(p);
	}
	s += st;
	return s;
}

text u2t(wstring u)
{
	const wchar_t* tstr = u.c_str();
	int len = WideCharToMultiByte(CP_ACP, 0, tstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, tstr, -1, str, len, NULL, NULL);
	return str;
}

wstring t2u(text t)
{
	int len = MultiByteToWideChar(CP_ACP, 0, t, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, t, -1, wstr, len);
	wstring s(wstr);
	return s;
}

string l2s(int64 num) {
	return to_string(num);
}

int64 s2l(string str) {
	return _atoi64(str.c_str());
}

string i2s(int32 num) {
	return to_string(num);
}

int32 s2i(string str) {
	return atoi(str.c_str());
}

text l2t(int64 num) {
	char* buf = new char[65];
	_i64toa_s(num, buf, 65, 10);
	return buf;
}

int64 t2l(text text) {
	return _atoi64(text);
}

int32 t2i(text text) {
	return atoi(text);
}

text i2t(int32 num) {
	char* buf = new char[33];
	_itoa_s(num, buf, 33, 10);
	return buf;
}



text s2t(string str) {
	return u2t(eec(s2u(str)));
}

string t2s(text text) {
	return u2s(edc(t2u(text)));
}

bin f2b(string path) {
	ifstream file(path, std::ios::binary);
	file.seekg(0, ios::end);
	int length = (int)file.tellg();
	file.seekg(0, ios::beg);
	char* buffer = new char[length];
	file.read(buffer, length);
	file.close();
	bin ret = (uint8*)buffer;
	return ret;
}

vector<int64> s2ls(string str, string p) {
	vector<int64> l;
	string s = str;
	if (s.substr(s.length() - p.length(), p.length()) != p) {
		s += p;
	}
	int size = s.size();
	for (int pos, i = 0; i < size; i++) {
		pos = s.find(p, i);
		if (pos < size)
		{
			string st = s.substr(i, pos - i);
			l.push_back(t2l(st.c_str()));
			i = pos + p.length() - 1;
		}
	}
	return l;
}