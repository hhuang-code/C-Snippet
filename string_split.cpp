    /*
      Split s by c, and the result is stored in v.
    */
    void split(const string& s, vector<string>& v, const string& c){
        string::size_type pos1, pos2;
        pos1 = 0;
        pos2 = s.find(c);
        while(pos2 != string::npos){
            v.push_back(s.substr(pos1, pos2 - pos1));
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length()){
            v.push_back(s.substr(pos1));
        }
    }
