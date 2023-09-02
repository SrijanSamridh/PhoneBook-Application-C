#include <curl/curl.h>

// Function to send a POST request
int sendPostRequest(const char *url, const char *post_data)
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();

    if (curl)
    {
        // Set the URL for the POST request
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // Set the request type to POST
        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        // Set the POST data
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);

        // Set custom headers
        // Setting the Content-Type header to indicate JSON data
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

        // Performing the POST request
        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            fprintf(stderr, "POST request failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return 1; // Return an error code
        }

        // Clean up
        curl_easy_cleanup(curl);
    }
    else
    {
        fprintf(stderr, "Failed to initialize libcurl for POST request.\n");
        return 1; // Return an error code
    }

    return 0; // Return 0 for success
}