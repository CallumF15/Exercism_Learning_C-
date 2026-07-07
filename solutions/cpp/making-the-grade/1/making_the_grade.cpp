#include <array>
#include <string>
#include <vector>
#include <stdexcept>

// Round down all provided student scores.
std::vector<int> round_down_scores(const std::vector<double>& student_scores) {
    // TODO: Implement round_down_scores)

    std::vector<int> numbers;
    numbers.reserve(student_scores.size());

    for(auto score : student_scores){
           numbers.push_back(static_cast<int>(score)); 
    }
    
    return numbers;
}

// Count the number of failing students out of the group provided.
int count_failed_students(const std::vector<int>& student_scores) {

    int count {};
    // TODO: Implement count_failed_students
    for(auto score : student_scores){
        if(score <= 40){
            count++;
        }
    }
    
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(const int& highest_score) {

    if (highest_score < 44)
        throw std::invalid_argument("Highest score is too low to create grade intervals");
    
    const int MIN_GRADE = 41;
    int interval = (highest_score - 40) / 4;

    std::array<int, 4> grades = {
        MIN_GRADE,
        MIN_GRADE + interval,
        MIN_GRADE + (2 * interval),
        MIN_GRADE + (3 * interval)
    };

    return grades;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(const std::vector<int>& student_scores, const std::vector<std::string>& student_names) 
{
    std::vector<std::string> student_list;
    
    if (student_scores.size() != student_names.size())
        return student_list; // or handle the error however your other function does
    
    for (std::size_t i = 0; i < student_scores.size(); ++i)
    {
        student_list.push_back(
            std::to_string(i + 1) + ". " + 
            student_names[i] + ": " + 
            std::to_string(student_scores[i]));
    }

    return student_list;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(const std::vector<int>& student_scores, const std::vector<std::string>& student_names) {

    if (student_names.size() != student_scores.size())
        return "invalid array";

    std::string HighestScoreNames {};

    for (std::size_t i = 0; i < student_scores.size(); ++i) 
    {
            if(student_scores[i] == 100)
                return student_names[i];
            
    }
    
    return "";
}
