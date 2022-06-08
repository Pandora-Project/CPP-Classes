#include <iostream>
#include <string>
#include <curl/curl.h>
#include <cstring>
#include <stdio.h>
#include <stdarg.h>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

json parser(string data, string value = "")
{
    auto j3 = json::parse(data);
    json object = j3;
    if (value == "")
    {
        return j3;
    }
    return j3.at(value);
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
}

string create_addr(int argc, ...)
{
    int i;
    va_list vl;
    va_start(vl, argc);
    string address = "";
    for (i = 0; i < argc; i++)
    {
        address.append(va_arg(vl, string));
    }
    va_end(vl);
    return address;
}

json fluctuation(string start_date, string end_date, string base, string symbols)
{
    start_date.append("&end_date=");
    end_date.append("&base=");
    base.append("&symbols=");

    string address = "https://api.apilayer.com/exchangerates_data/fluctuation?start_date=";
    address = create_addr(5, address, start_date, end_date, base, symbols);
    char *url;
    url = &address[0];

    CURL *curl;
    CURLcode res;
    string readBuffer;
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "apikey: yJ5I2q9YkXaupZWaN8RiStO5sQN1sFx3");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
    }
    curl_easy_cleanup(curl);
    return parser(readBuffer, "rates");
}

json exchange(string amount, string from_curr, string symbols)
{
    from_curr.append("&amount=");
    symbols.append("&from=");

    string address = "https://api.apilayer.com/exchangerates_data/convert?to=";
    address = create_addr(4, address, symbols, from_curr, amount);
    char *url;
    url = &address[0];

    CURL *curl;
    CURLcode res;
    string readBuffer;
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "apikey: yJ5I2q9YkXaupZWaN8RiStO5sQN1sFx3");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
    }
    curl_easy_cleanup(curl);
    return parser(readBuffer, "result");
}

json exchange_rate(string base, string symbols)
{
    symbols.append("&base=");

    string address = "https://api.apilayer.com/exchangerates_data/latest?symbols=";
    address = create_addr(3, address, symbols, base);
    char *url;
    url = &address[0];

    CURL *curl;
    CURLcode res;
    string readBuffer;
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "apikey: yJ5I2q9YkXaupZWaN8RiStO5sQN1sFx3");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
    }
    curl_easy_cleanup(curl);
    return parser(readBuffer, "rates");
}

json symbols()
{
    CURL *curl;
    CURLcode res;
    string readBuffer;
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.apilayer.com/exchangerates_data/symbols");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "apikey: yJ5I2q9YkXaupZWaN8RiStO5sQN1sFx3");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
    }
    curl_easy_cleanup(curl);
    return parser(readBuffer);
}

json date_rate(string date, string base, string symbols /*=""*/)
{
    date.append("?symbols=");
    symbols.append("&base=");

    string address = "https://api.apilayer.com/exchangerates_data/";
    address = create_addr(4, address, date, symbols, base);
    char *url;
    url = &address[0];
    CURL *curl;
    CURLcode res;
    string readBuffer;
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "apikey: yJ5I2q9YkXaupZWaN8RiStO5sQN1sFx3");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
    }
    curl_easy_cleanup(curl);
    return parser(readBuffer, "rates");
}