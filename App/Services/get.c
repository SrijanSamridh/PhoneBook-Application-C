#include<curl/curl.h>

// Function to send a GET request
int sendGetRequest(const char* url) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();

    if (curl) {
        // Set the URL for the GET request
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // set the header
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Accept: application/json");

        // Use a callback function to write the response data to stdout
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

        // Perform the GET request
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "GET request failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return 1; // Return an error code
        }

        // Clean up
        curl_easy_cleanup(curl);


        
    } else {
        fprintf(stderr, "Failed to initialize libcurl for GET request.\n");
        return 1; // Return an error code
    }

    return 0; // Return 0 for success
}

// Function to search for a number with a given name using a GET request to the API server (http://localhost:8080/api/search/<name>)
int searchNumber(const char* name) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();

    if (curl) {
        // Set the URL for the GET request
        char url[100];
        snprintf(url, sizeof(url), "https://c-project-backend-server-srijansamridh.vercel.app/api/search/%s", name);
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // set the header
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Accept: application/json");

        // Use a callback function to write the response data to stdout
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

        // Perform the GET request
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "GET request failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return 1; // Return an error code
        }

        // Clean up
        curl_easy_cleanup(curl);
    }
    else {
        fprintf(stderr, "Failed to initialize libcurl for GET request.\n");
        return 1; // Return an error code
    }

    return 0; // Return 0 for success
}
