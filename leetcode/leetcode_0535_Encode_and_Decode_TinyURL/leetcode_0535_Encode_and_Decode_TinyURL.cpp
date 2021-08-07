class Solution {
public:
    unordered_map<string,string> codes , urls;
    //codes --> code to URL
    //urls --> url to code
    const string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*(){}[]|\/";
    // Encodes a URL to a shortened URL.
    string getCode(string url){
        string code = "";
        for(int i=0;i<8;i++){
            code += chars[rand()%chars.length()];
        }
        code = "http://tinyurl.com/"+code;
        return code;
    }
    
    string encode(string longUrl) {
        if(urls.find(longUrl)!=urls.end())
            return urls[longUrl];
        string code = getCode(longUrl);
        while(codes.find(code)!=codes.end())
            code = getCode(longUrl);
        codes[code] = longUrl;
        urls[longUrl] = code;
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return codes[shortUrl];
    }
};