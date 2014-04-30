#include<stdio.h>
#include<stdlib.h>
#include <curl/curl.h>
#include <openssl/md5.h>

int main()
{
    char buf[1024];

    CURL *curl;
    CURLcode res;
    string url;
    string post_fields;
    url = "http://api.jiankongbao.com/site/task/list.json"
    curl = curl_easy_init();
	
    if(curl) 
    {   
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);
        curl_easy_setopt(curl,CURLOPT_USERPWD,"644104436@qq.com:ucloud.cn");
        curl_easy_setopt(curl,CURLOPT_HTTPGET,true);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, buf);
        //curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_fields.c_str()); 

        res = curl_easy_perform(curl);
        if(CURLE_OK == res)
        {
            char *data;
            res = curl_easy_getinfo(curl, CURLINFO_PRIVATE, &data);
        }
}

}
