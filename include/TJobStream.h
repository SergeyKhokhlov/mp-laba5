#include "TQueue.h"
#include <cstdlib>

class TJobStream {
private:
	double jobIntense; // ������������� ������ �����
	int jobId;
public:
	TJobStream(double Intense);
	int GetNewJob(void); // ��������� ������ �������
};


TJobStream::TJobStream(double Intense) {
	if (Intense >= 0.0 && Intense <= 1.0) {
		this->jobIntense = Intense;
		jobId = 1;
	} else throw "error with intense (0 <= intense <= 1)";
}

size_t TJobStream::GetNewJob(void) {
	if (static_cast<double > (std::rand()) / static_cast<double>(RAND_MAX) <= jobIntense) {
		jobId++;
		return jobId - 1;
	} 
	return 0;
}
