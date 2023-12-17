#include "TQueue.h"
#include <cstdlib>
class TProc {
	private:
		double procRate;
		int JobId;
	public:
		TProc(int Rate);
		int IsProcBusy(void); // процессор занят?
		int RunNewJob(int JobId); // приступить к выполнению нового задания
}


TProc::TProc(double rate) {
	if (rate >= 0.0 && rate <= 1.0) {
		procRate = rate;
	} else throw "error with rate (0 <= rate <= 1)";
}

int TProc::IsProcBusy(void) const noexcept {
	if (jobs.isEmpty()) return 0;
	return jobs.busy_checker();
}

int TProc::RunNewJob(int JobId) {
	if (JobId > 0) {
		if (!(jobs.isFull())) {
			jobs.push(JobId);
			return JobId;
		}
	}
	return 0;
}