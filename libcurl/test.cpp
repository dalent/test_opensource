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
    url = "http://3tong.net/http/SendSms"
    post_fields = "Account=dh20891&Password=daffacc5d5b2482ab603715a6d68566d&Phone=15201903989&Content=ucloudhelloworld";
    //post_fields = FormatString("%s&sendDateTime",post_fields.c_str());
    curl = curl_easy_init();
	
    if(curl) 
    {   
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, buf);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_fields.c_str()); 

        res = curl_easy_perform(curl);
        if(CURLE_OK == res)
        {
            char *data;
            res = curl_easy_getinfo(curl, CURLINFO_PRIVATE, &data);

        }
}

}
