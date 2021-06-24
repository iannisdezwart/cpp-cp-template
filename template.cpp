#include <bits/stdc++.h>

using namespace std;

// Types and formatting

#define let auto

using uc = uint8_t;
using sc = int8_t;
using us = uint16_t;
using ss = int16_t;
using ui = uint32_t;
using si = int32_t;
using ul = uint64_t;
using sl = int64_t;

using sn = string;

using vi = vector<si>;
using vl = vector<sl>;
using vs = vector<string>;

#define pb push_back
#define put cout <<

#define db double
#define prc(n) setprecision(n) <<
#define fix(n) fixed << setprecision(n) <<

#define PI 3.1415926535897932384626433832795
#define E 2.7182818284590452353602874713526

// Control flow

/**
 *  Repeat loop.
 *  i: [ 0, times >.
 */
#define lp(i, times) for (auto [ i, first, last ] = tuple(0, true, false); \
	first = i == 0, last = i == times - 1, i < times; i++)

/**
 *  Regular for loop.
 *  i: [ start, end >.
 */
#define fr(i, start, end) for (auto [ i, first, last ] = tuple(start, true, false); \
	first = i == start, last = i == end - 1, i < end; i++)

/**
 *  Reverse repeat loop.
 *  i: < times, 0 ].
 */
#define rlp(i, times) for (auto [ i, first, last ] = tuple(times - 1, true, false); \
	first = i == 0, last = i == times - 1, i >= 0; i--)

/**
 *  Reverse for loop.
 *  i: < end, start ].
 */
#define rfr(i, start, end) for (auto [ i, first, last ] = tuple(end - 1, true, false); \
	first = i == start, last = i == end - 1, i >= start; i--)

/**
 *  Loop over items  ** by reference **.
 *  i: items in data structure.
 */
#define lpi(i, vec) for (auto [ i, i##i, first, last ] = tuple(vec[0], 0, true, false); \
	i = vec[i##i], first = i##i == 0, last = i##i == len(vec) - 1, i##i < len(vec); i##i++)

// Utility functions

/**
 *  Returns the number of elements on the vector.
 */
template <typename T>
size_t len(const T& vec) { return vec.size(); }

/**
 *  std::string to int32_t.
 */
int sti(const string& str) { return stoi(str); }

/**
 *  std::string to int64_t.
 */
sl stl(const string& str) { return stoll(str); }

// Getting stuff from stdin

#define gs(name) string name; getline(cin, name)
#define guc(name) uc name; cin >> name
#define gsc(name) sc name; cin >> name
#define gus(name) us name; cin >> name
#define gss(name) ss name; cin >> name
#define gui(name) ui name; cin >> name
#define gsi(name) si name; cin >> name
#define gul(name) ul name; cin >> name
#define gsl(name) sl name; cin >> name

#define gdb(name) db name; cin >> name

// Putting stuff on stdout

#define pf(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define pnl cout << '\n'

// Vector algorithms

/**
 * Bool: VEC contains SEARCH at least once.
 * Use cnt(VEC, SEARCH) to get the number of occurences.
 */
template <typename T>
bool has(const vector<T>& vec, const T& search)
{
	for (const T& i : vec)
	{
		if (i == search) return true;
	}

	return false;
}

/**
 *  Sums the values in VEC.
 *  @tparam  Ret  The number return type. Defaults to int32_t.
 */
template <typename Ret = sl, typename T>
Ret sum(const vector<T>& vec)
{
	sl out = 0;
	for (const T& val : vec) out += val;
	return out;
}

// Higher order functions

template <typename T>
struct NoOp
{
	typedef T type;
};

/**
 *  Maps values from VEC by CONV.
 */
template <typename To, typename From>
vector<To> mp(const vector<From>& vec, typename NoOp<function<To (const From&)>>::type conv)
{
	vector<To> out;

	for (const From& val : vec)
	{
		out.push_back(conv(val));
	}

	return out;
}

/**
 *  Maps the chars of STR by CONV.
 */
template <typename To>
vector<To> mp(const string& str, typename NoOp<function<To (char)>>::type conv)
{
	vector<To> out;

	for (char c : str)
	{
		out.push_back(conv(c));
	}

	return out;
}

/**
 *  Executes CB for each value in VEC.
 */
template <typename T>
void each(const vector<T>& vec, typename NoOp<function<void (const T&)>>::type cb)
{
	for (const T& val : vec)
	{
		cb(val);
	}
}

/**
 *  Executes CB for each char in STR.
 */
void each(const string& str, typename NoOp<function<void (char)>>::type cb)
{
	for (char c : str)
	{
		cb(c);
	}
}

/**
 *  Filters VEC by CB.
 */
template <typename T>
vector<T> flt(const vector<T>& vec, typename NoOp<function<bool (const T&)>>::type cb)
{
	vector<T> out;

	for (const T& val : vec)
	{
		if (cb(val))
		{
			out.push_back(val);
		}
	}

	return out;
}

// String algorithms

/**
 *  Counts the number of SEARCH occurences in STR.
 */
size_t cnt(const string& str, const string& search)
{
	size_t offset = 0;
	size_t ans = 0;

	while ((offset = str.find(search, offset)) != string::npos)
	{
		ans++;
		offset += search.size();
	}

	return ans;
}

/**
 *  Counts the number of SEARCH occurences in STR.
 */
size_t cnt(const string& str, char search)
{
	return count(str.begin(), str.end(), search);
}

// Todo: could improve time by using for loop.

/**
 *  Bool: STR starts with SEARCH
 */
bool start(const string& str, const string& search)
{
	if (search.size() > str.size()) return false;
	if (str.substr(0, search.size()) == search) return true;
	return false;
}

// Todo: could improve time by using reverse for loop.

/**
 *  Bool: STR ends with SEARCH
 */
bool end(const string& str, const string& search)
{
	if (search.size() > str.size()) return false;
	if (str.substr(str.size() - search.size(), search.size()) == search) return true;
	return false;
}

/**
 * Bool: STR contains SEARCH at least once.
 * Use cnt(STR, SEARCH) to get the number of occurences.
 */
bool has(const string& str, const string& search)
{
	if (str.find(search) == string::npos) return false;
	return true;
}

/**
 *  Counts the number of SEARCH occurences in VEC.
 */
template <typename T>
size_t cnt(const vector<T>& vec, const T& search)
{
	size_t ans = 0;

	for (const T& i : vec)
	{
		if (i == search) ans++;
	}

	return ans;
}

/**
 *  All [a-z] --> [A-Z].
 */
string upcase(string str)
{
	for (char& c : str)
	{
		if (c >= 'a' && c <= 'z') c -= 32;
	}

	return str;
}

/**
 *  All [A-Z] --> [a-z].
 */
string locase(string str)
{
	for (char& c : str)
	{
		if (c >= 'A' && c <= 'Z') c += 32;
	}

	return str;
}

/**
 *  Pad  ** begin **  of std::string.
 *  Pads the beginning with C until len(STR) == LEN.
 */
string padb(const string& str, size_t len, char c)
{
	if (str.size() >= len) return str;
	size_t diff = len - str.size();
	return string(len, c) + str;
}

/**
 *  Pad  ** end **  of std::string.
 *  Pads the end with C until len(STR) == LEN.
 */
string pade(const string& str, size_t len, char c)
{
	if (str.size() >= len) return str;
	size_t diff = len - str.size();
	return str + string(len, c);
}

/**
 *  Centres STR with C padded to LEN on the left and right.
 */
string centre(const string& str, size_t len, char c = ' ')
{
	if (str.size() >= len) return str;
	size_t diff = len - str.size();
	size_t left = diff / 2;
	size_t right = diff / 2;
	if (diff != left + right) left++;
	return string(left, c) + str + string(right, c);
}

/**
 *  Repeats STR TIMES times.
 */
string rpt(const string& str, size_t times)
{
	string out;
	for (size_t i = 0; i < times; i++) out += str;
	return out;
}

/**
 *  Replaces  ** all **  instances of FIND by REPL in STR.
 */
string rpl(const string& str, const string& find, const string& repl)
{
	string out = str;
	size_t offset = 0;

	while ((offset = out.find(find, offset)) != string::npos)
	{
		out.erase(offset, find.size());
		out.insert(offset, repl);
		offset += repl.size();
	}

	return out;
}

/**
 *  Removes  ** all **  instances of FIND in STR.
 */
string rm(const string& str, const string& find)
{
	string out = str;
	size_t offset = 0;

	while ((offset = out.find(find, offset)) != string::npos)
	{
		out.erase(offset, find.size());
	}

	return out;
}

/**
 *  Removes  ** all **  instances of FIND in STR.
 */
string rm(const string& str, char find) { return rm(str, string(1, find)); }

/**
 *  Takes out all FIND from STR.
 */
string tk(const string& str, const vector<char>& find)
{
	string out = str;

	for (char c : find)
	{
		out = rm(out, c);
	}

	return out;
}

/**
 *  Keeps all FIND of STR, discarding the rest.
 */
string kp(const string& str, const vector<char>& find)
{
	string out;

	for (char c : str)
	{
		if (has(find, c)) out += c;
	}

	return out;
}

const vector<char> vow = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };
const vector<char> vowy = { 'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o',
	'u', 'y' };
const vector<char> cons = { 'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
	'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z', 'b', 'c', 'd',
	'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w',
	'x', 'y', 'z' };
const vector<char> consy = { 'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
	'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Z', 'b', 'c', 'd', 'f',
	'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w',
	'x', 'z' };

/**
 *  Keeps vowels of STR.
 */
string kpvow(const string& str) { return kp(str, vow); }

/**
 *  Keeps consonants of STR.
 */
string kpcons(const string& str) { return kp(str, cons); }

/**
 *  Keeps vowels (incl. Y) of STR.
 */
string kpvowy(const string& str) { return kp(str, vowy); }

/**
 *  Keeps consonants (excl. Y) of STR.
 */
string kpconsy(const string& str) { return kp(str, consy); }

/**
 *  Takes out vowels of STR.
 */
string tkvow(const string& str) { return tk(str, vow); }

/**
 *  Takes out consonants of STR.
 */
string tkcons(const string& str) { return tk(str, cons); }

/**
 *  Takes out vowels (incl. Y) of STR.
 */
string tkvowy(const string& str) { return tk(str, vowy); }

/**
 *  Takes out consonants (excl. Y) of STR.
 */
string tkconsy(const string& str) { return tk(str, consy); }

/**
 *  Splits STR delimited by FIND.
 *  FIND is left out in the returned vector<std::string>.
 */
vector<string> spl(const string& str, const string& find)
{
	vector<string> out;
	size_t left = 0;
	size_t right = 0;

	while ((right = str.find(find, left)) != string::npos)
	{
		out.push_back(str.substr(left, right - left));
		left = right + find.size();
	}

	out.push_back(str.substr(left));

	return out;
}

/**
 *  Splits STR by contiguous blocks of chars.
 */
vector<string> splb(const string& str)
{
	vector<string> out;
	if (str.size() == 0) return out;

	char c = str[0];
	size_t left = 0;
	size_t len = 1;

	for (size_t i = 1; i < str.size(); i++)
	{
		if (str[i] != c)
		{
			out.push_back(str.substr(left, len));
			c = str[i];
			left = i;
			len = 1;
		}
		else
		{
			len++;
		}
	}

	out.push_back(str.substr(left));
	return out;
}

/**
 *  Bool: C is a whitespace char.
 */
bool whtsp(char c) { return c == ' ' || c == '\t' || c == '\n'; }

/**
 *  Splits STR into words.
 */
vector<string> splw(const string& str)
{
	vector<string> out;
	if (str.size() == 0) return out;

	size_t left = 0;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (whtsp(str[i]))
		{
			if (i != 0 && !whtsp(str[i - 1]))
			{
				out.push_back(str.substr(left, i - left));
			}

			left = i + 1;
		}
	}

	if (!whtsp(str[str.size() - 1]))
	{
		out.push_back(str.substr(left));
	}

	return out;
}

/**
 *  Removes leading and trailing whitespace from STR.
 */
string trm(string str)
{
	size_t left = 0;
	size_t right = str.size();

	while (left < str.size() && whtsp(str[left])) left++;
	while (right > 0 && whtsp(str[right - 1])) right--;

	if (left >= right) return "";
	return str.substr(left, right - left);
}

/**
 *  Converts STR into a vector<char>.
 */
vector<char> stca(const string& str)
{
	vector<char> out;

	for (char c : str)
	{
		out.push_back(c);
	}

	return out;
}

/**
 *  Reverses STR.
 */
string rev(string str)
{
	for (size_t i = 0; i < str.size() / 2; i++)
	{
		swap(str[i], str[str.size() - i - 1]);
	}

	return str;
}

/**
 *  Interlaces STR1 and STR2.
 *  len(STR1) and len(STR2) have to be equal,
 *  or len(STR1) has to beone more than len(STR2).
 */
string intl(const string& str1, const string& str2)
{
	string out;
	size_t len2 = str2.size();

	for (size_t i = 0; i < str1.size(); i++)
	{
		out += str1[i];
		if (i != len2) out += str2[i];
	}

	return out;
}

/**
 *  Splits STR into segments of equal length.
 *  The right most segment is shorter than SEG_SIZ if len(STR) % SEG_SIZ != 0.
 */
vector<string> seg(const string& str, size_t seg_siz)
{
	vector<string> out;

	for (size_t i = 0; i < str.size(); i += seg_siz)
	{
		out.push_back(str.substr(i, seg_siz));
	}

	return out;
}

/**
 *  Splits STR into two segments of equal length.
 */
vector<string> halve(const string& str)
{
	size_t seg_siz = str.size() / 2;
	if (str.size() % 2) seg_siz++;
	return seg(str, seg_siz);
}

const string& to_string(const string& str) { return str; }

/**
 *  Joins the numbers in VEC into a string, seperated by SEP.
 */
template <typename T>
string jn(const vector<T>& vec, string sep = " ")
{
	string out;

	for (size_t i = 0; i < vec.size(); i++)
	{
		out += to_string(vec[i]);
		if (i != vec.size() - 1) out += sep;
	}

	return out;
}

/**
 *  Matches STR with REGEX.
 */
bool remat(const string& str, const string& regex)
{
	return regex_match(str, std::regex(regex));
}

/**
 *  Searches STR for REGEX.
 */
bool resrc(const string& str, const string& regex)
{
	return regex_search(str, std::regex(regex));
}

/**
 *  Replaces in STR with REPL by REGEX.
 */
string rerpl(const string& str, const string& regex, const string& repl)
{
	return regex_replace(str, std::regex(regex), repl);
}

// Time

/**
 *  Converts hh:mm -> timestamp.
 */
size_t hh_mm_to_ts(const string& str)
{
	vector<string> hh_mm = spl(str, ":");

	int hh = sti(hh_mm[0]);
	int mm = sti(hh_mm[1]);

	return hh * 60 + mm;
}

/**
 *  Converts timestamp -> hh:mm.
 */
string ts_to_hh_mm(size_t ts)
{
	int hh = ts / 60;
	int mm = ts % 60;

	return to_string(hh) + ":" + to_string(mm);
}

// Units

double db_sqrt(double v)  { return sqrt(v); }
double db_ln(double v)    { return log(v); }
double db_log10(double v) { return log10(v); }
double db_abs(double v)   { return abs(v); }
double db_cos(double v)   { return cos(v); }
double db_sin(double v)   { return sin(v); }
double db_tan(double v)   { return tan(v); }
double db_acos(double v)  { return acos(v); }
double db_asin(double v)  { return asin(v); }
double db_atan(double v)  { return atan(v); }
double db_ceil(double v)  { return ceil(v); }
double db_floor(double v) { return floor(v); }

class Wt
{
	private:
		double kg;

	public:
		static const constexpr double g_per_kg = 1000;
		static const constexpr double si_tonnes_per_kg = 0.001;
		static const constexpr double lbs_per_kg = 2.20462;
		static const constexpr double oz_per_kg = 35.274;
		static const constexpr double us_tons_per_kg = 0.00110231;

		explicit constexpr Wt(double kg) : kg(kg) {}

		double to_kg()        { return kg; }
		double to_g()         { return kg * Wt::g_per_kg; }
		double to_si_tonne()  { return kg * Wt::si_tonnes_per_kg; }
		double to_lbs()       { return kg * Wt::lbs_per_kg; }
		double to_oz()        { return kg * Wt::oz_per_kg; }
		double to_us_ton()    { return kg * Wt::us_tons_per_kg; }

		constexpr Wt operator+(const Wt& other) { return Wt(kg + other.kg); }
		constexpr Wt operator-(const Wt& other) { return Wt(kg - other.kg); }
		constexpr Wt operator*(const Wt& other) { return Wt(kg * other.kg); }
		constexpr Wt operator/(const Wt& other) { return Wt(kg / other.kg); }

		Wt apply(function<double (double)> fn) { return Wt(fn(kg)); }
		Wt sqrt() { return apply(db_sqrt); };
		Wt ln() { return apply(db_ln); };
		Wt log10() { return apply(db_log10); };
		Wt abs() { return apply(db_abs); };
		Wt cos() { return apply(db_cos); };
		Wt sin() { return apply(db_sin); };
		Wt tan() { return apply(db_tan); };
		Wt acos() { return apply(db_acos); };
		Wt asin() { return apply(db_asin); };
		Wt atan() { return apply(db_atan); };
		Wt ceil() { return apply(db_ceil); };
		Wt floor() { return apply(db_floor); };
};

constexpr Wt operator"" _kg      (long double v) { return Wt(v); }
constexpr Wt operator"" _g       (long double v) { return Wt(v / Wt::g_per_kg); }
constexpr Wt operator"" _si_tonne(long double v) { return Wt(v / Wt::si_tonnes_per_kg); }
constexpr Wt operator"" _lbs     (long double v) { return Wt(v / Wt::lbs_per_kg); }
constexpr Wt operator"" _oz      (long double v) { return Wt(v / Wt::oz_per_kg); }
constexpr Wt operator"" _us_ton  (long double v) { return Wt(v / Wt::us_tons_per_kg); }

class Lt
{
	private:
		double m;

	public:
		static const constexpr double mm_per_m = 1000;
		static const constexpr double cm_per_m = 100;
		static const constexpr double km_per_m = 0.001;
		static const constexpr double in_per_m = 39.3701;
		static const constexpr double ft_per_m = 3.28084;
		static const constexpr double mi_per_m = 0.000621371;
		static const constexpr double yd_per_m = 1.09361296;
		static const constexpr double nm_per_m = 0.00053995663640604751;

		explicit constexpr Lt(double m) : m(m) {}

		double to_m()  { return m; }
		double to_mm() { return m * Lt::mm_per_m; }
		double to_cm() { return m * Lt::cm_per_m; }
		double to_km() { return m * Lt::km_per_m; }
		double to_in() { return m * Lt::in_per_m; }
		double to_ft() { return m * Lt::ft_per_m; }
		double to_mi() { return m * Lt::mi_per_m; }
		double to_yd() { return m * Lt::yd_per_m; }
		double to_nm() { return m * Lt::nm_per_m; }

		static Lt from_ft_in(double ft, double in)
		{
			return Lt((ft + in / 12.0) / Lt::ft_per_m);
		}

		ssize_t ft_part() { return std::floor(to_ft()); }
		double in_part() { return (to_ft() - ft_part()) * 12.0; }

		constexpr Lt operator+(const Lt& other) { return Lt(m + other.m); }
		constexpr Lt operator-(const Lt& other) { return Lt(m - other.m); }
		constexpr Lt operator*(const Lt& other) { return Lt(m * other.m); }
		constexpr Lt operator/(const Lt& other) { return Lt(m / other.m); }

		Lt apply(function<double (double)> fn) { return Lt(fn(m)); }
		Lt sqrt() { return apply(db_sqrt); };
		Lt ln() { return apply(db_ln); };
		Lt log10() { return apply(db_log10); };
		Lt abs() { return apply(db_abs); };
		Lt cos() { return apply(db_cos); };
		Lt sin() { return apply(db_sin); };
		Lt tan() { return apply(db_tan); };
		Lt acos() { return apply(db_acos); };
		Lt asin() { return apply(db_asin); };
		Lt atan() { return apply(db_atan); };
		Lt ceil() { return apply(db_ceil); };
		Lt floor() { return apply(db_floor); };
};

constexpr Lt operator"" _m (long double v) { return Lt(v); }
constexpr Lt operator"" _mm(long double v) { return Lt(v / Lt::mm_per_m); }
constexpr Lt operator"" _cm(long double v) { return Lt(v / Lt::cm_per_m); }
constexpr Lt operator"" _km(long double v) { return Lt(v / Lt::km_per_m); }
constexpr Lt operator"" _in(long double v) { return Lt(v / Lt::in_per_m); }
constexpr Lt operator"" _ft(long double v) { return Lt(v / Lt::ft_per_m); }
constexpr Lt operator"" _mi(long double v) { return Lt(v / Lt::mi_per_m); }
constexpr Lt operator"" _yd(long double v) { return Lt(v / Lt::yd_per_m); }
constexpr Lt operator"" _nm(long double v) { return Lt(v / Lt::nm_per_m); }

// Code starts here

int main()
{
	
}