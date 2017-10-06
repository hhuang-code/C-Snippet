// Delete leading and tailing whitespace

string trim(const string& str){
	const auto pos1 = str.find_first_not_of(' ');
	if(pos1 == string::npos){
		return "";
	}else{
		const auto pos2 = str.find_last_not_of(' ');
		const auto len = pos2 - pos1 + 1;

		return str.substr(pos1, len);
	}
}
