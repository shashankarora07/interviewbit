#include <cerrno>
#include <cinttypes>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>


void init_turnstile(const uint32_t max_num_tracked_employees);
void enter_employee(const uint32_t employee_id, const uint64_t timestamp);
uint64_t get_last_entry_time(const uint32_t employee_id);

#include <map>
#include <unordered_map>
//using namespace std;
// You may place helper functions, variables, and type definitions here
std::unordered_map<long, long long> newMap;
uint32_t MaxNo_emp = 0;

void init_turnstile(const uint32_t max_num_tracked_employees) {
    // Implement your code here!
    newMap.clear();
    MaxNo_emp = max_num_tracked_employees;
    std::cout << "MaxNo_emp:  " << MaxNo_emp << std::endl; 
}

void enter_employee(const uint32_t employee_id, const uint64_t timestamp) {
    // Implement your code here!

    newMap.insert({employee_id,timestamp});
    
        if (newMap.find(employee_id) != newMap.end()) {
            std::cout << "if employee id found" << std::endl;
            newMap.erase(employee_id);
            newMap.insert({employee_id,timestamp});
           for (auto i = newMap.begin(); i != newMap.end(); i++) {
            std::cout << "i->first:  " << i->first << "and i->second:  "<< i->second << std::endl;
            }
            std::cout << "=====================" << std::endl;

        }
        std::unordered_map<long, long long>:: iterator it = newMap.begin();
		long long last_entry = it->second;

        std::cout << "newMap.size() = " << newMap.size() << std::endl;
        if (newMap.size() > MaxNo_emp) {
            // replace new entry with Oldest timestamp
            //for (auto i = newMap.begin(); i != newMap.end(); i++) {
            while( it != newMap.end()) {
               // min_element(newMap.begin(), newMap.end(),compare) 
                if (it->second < last_entry)
                    last_entry = it->second;
				it++;
            }
            std::cout << "last_entry:  " << last_entry << std::endl;
            for (auto i = newMap.begin(); i != newMap.end(); i++) {
                if (i->second == last_entry) {
                    std::cout << "Removing:: i->first: " << i->first << " and i->second: "<< i->second << std::endl;
                    newMap.erase(i->first);
                    newMap.insert({employee_id,timestamp}); 
                    std::cout << "Inserting:: employee_id = "<< employee_id << " and timestamp = " << timestamp << std::endl;
                    std::cout << "$$$$$$$$$$$$$$$$$$$$" << std::endl;                }
            }
        }

        std::cout << "Show All Employee Entries" << std::endl;
        for (auto i = newMap.begin(); i != newMap.end(); i++) {
            std::cout << "i->first:  " << i->first << "and i->second:  "<< i->second << std::endl;
        }
        
}

uint64_t get_last_entry_time(const uint32_t employee_id) {
    // Implement your code here!
    for (auto i = newMap.begin(); i != newMap.end(); i++) {
        std::cout << "i->first:  " << i->first << "and i->second:  "<< i->second << std::endl;
        if (newMap.find(employee_id) != newMap.end())
            return i->second;
        else
            return 0;
        
    }
}

int main(void) {
    // We read lines in, one at a time, and pass them to the requisite functions
    for (std::string cur_line; std::getline(std::cin, cur_line);) {
        std::vector<long long> input_cmd;

        for(size_t cur_idx = 0; cur_idx < cur_line.length();) {
            size_t token_end_idx = cur_line.find(" ", cur_idx);
            if (token_end_idx == std::string::npos) {
                token_end_idx = cur_line.length();
            }
            const size_t token_length = token_end_idx - cur_idx;
            std::string token = cur_line.substr(cur_idx, token_length);

            // We use C-style integer parsing to better detect parse errors
            errno = 0;
            char *endptr;
            input_cmd.push_back(strtoll(token.c_str(), &endptr, 0));
            if (errno != 0 || (*endptr != '\n' && *endptr != '\0')) {
                fprintf(stderr, "Failed to parse test input command!\n");
                return -1;
            }

            cur_idx = token_end_idx + 1;
        }

        if (input_cmd.empty()) {
            fprintf(stderr, "Empty input command!\n");
            return -1;
        }

        // Process the received test command!
        switch (input_cmd[0]) {
            case 0:
                if (input_cmd.size() != 2 || input_cmd[1] < 0 || input_cmd[1] > UINT32_MAX) {
                    fprintf(stderr, "Bad command!\n");
                    return -1;
                }
                init_turnstile((uint32_t)input_cmd[1]);
                break;

            case 1:
                if (input_cmd.size() != 3 ||
                    input_cmd[1] < 0 ||
                    input_cmd[1] > UINT32_MAX ||
                    input_cmd[2] < 0)
                {
                    fprintf(stderr, "Bad command!\n");
                    return -1;
                }
                enter_employee((uint32_t)input_cmd[1], (uint64_t)input_cmd[2]);
                break;

            case 2:
                if (input_cmd.size() != 2 || input_cmd[1] < 0 || input_cmd[1] > UINT32_MAX) {
                    fprintf(stderr, "Bad command!\n");
                    return -1;
                }
                fprintf(stdout, "%" PRIu64 "\n", get_last_entry_time((uint32_t)input_cmd[1]));
                break;

            default:
                fprintf(stderr, "Bad command!\n");
                return -1;
        }
    }

    return 0;
}
