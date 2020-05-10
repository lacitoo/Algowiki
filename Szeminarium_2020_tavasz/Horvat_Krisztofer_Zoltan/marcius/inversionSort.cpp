#include <iostream>

using namespace std;


void invertPart(string& str, int from, int to) {
    while (from < to) {
        char c = str[from];
        str[from] = str[to];
        str[to] = c;
        ++from;
        --to;
    }
}

int solution(string& current, const string& desired) {
    int start = 0, end = 9, result = 0; //both included
    
    while (start < end && current[start] == desired[start]) {
        ++start;
    }
    while (start < end && current[end] == desired[end]) {
        --end;
    }

    while (start < end) {
        int copyToStart = 1, copyToEnd = 1;

        int toStartPos = current.find(desired[start]);
        while (toStartPos - copyToStart >= start && current[toStartPos - copyToStart] == desired[start + copyToStart]) {
            ++copyToStart;
        }

        int toEndPos = current.find(desired[end]);
        while (toEndPos + copyToEnd <= end && current[toEndPos + copyToEnd] == desired[end - copyToEnd]) {
            ++copyToEnd;
        }

        if (copyToEnd > copyToStart) {
            invertPart(current, toEndPos, end);
            end -= copyToEnd;
        } else {
            invertPart(current, start, toStartPos);
            start += copyToStart;
        }

        while (start < end && current[start] == desired[start]) {
            ++start;
        }
        while (start < end && current[end] == desired[end]) {
            --end;
        }

        ++result;
    }

    return result;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string current, desired;
    cin >> current >> desired;

    while (current != "*" || desired != "*"){
        cout << solution(current, desired) << endl;
        cin >> current >> desired;
    }

    return 0;
}