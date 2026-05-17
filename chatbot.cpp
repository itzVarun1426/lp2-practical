#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Response {
    string keyword;
    string reply;
    int priority;
};

void selectionSort(vector<Response>& arr) {
    int n = arr.size();
    
    for(int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        
        for(int j = i + 1; j < n; j++) {
            if(arr[j].priority > arr[maxIndex].priority) {
                maxIndex = j;
            }
        }
        
        // swap
        if(maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
        }
    }
}

int main() {
    vector<Response> database = {
        {"track", "You can track your order in the 'My Orders' section.", 8},
        {"refund", "Your refund will be processed within 5-7 working days.", 10},
        {"cancel", "You can cancel your order before it is shipped.", 7},
        {"payment", "Please check your payment details or try another method.", 6},
        {"delivery", "Delivery usually takes 3-5 business days.", 5}
    };

    string userInput;

    cout << "🤖 Chatbot: Hello! How can I help you?\n";
    cout << "Type 'exit' to quit.\n\n";

    while(true) {
        cout << "You: ";
        getline(cin, userInput);

        // convert to lowercase
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

        if(userInput == "exit") {
            cout << "🤖 Chatbot: Thank you! Have a great day.\n";
            break;
        }

        vector<Response> matched;

        // keyword matching
        for(auto &res : database) {
            if(userInput.find(res.keyword) != string::npos) {
                matched.push_back(res);
            }
        }

        if(matched.empty()) {
            cout << "🤖 Chatbot: Sorry, I didn't understand. Please try again.\n";
        } else {
            // 🔥 Apply Selection Sort
            selectionSort(matched);

            // show best response
            cout << "🤖 Chatbot: " << matched[0].reply << "\n";
        }
    }

    return 0;
}