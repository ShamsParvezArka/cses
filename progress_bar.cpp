#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <ranges>
#include <functional>

std::function<void(unsigned int)> csleep = [] (unsigned int t) {
	std::this_thread::sleep_for(std::chrono::milliseconds(t));
};

class ProgressBar {
public:
	ProgressBar(std::string progress_bar_shape) {
		progress_bar_shape_ = progress_bar_shape;
		delay_ = 100 / bar_size_;
	}

	void initialize() {
		printf("\e[?25l");
		for (int i = 0; i < bar_size_ + 1; i++) {
			std::cout << " ";
		}
		std::cout << "]";
		std::cout << '\r' << std::flush;
		std::cout << "[" << std::flush;
	}

	void update() {
		initialize();
		for (int i = 0; i < bar_size_; i++) {
			std::cout << progress_bar_shape_;
			csleep(100 * delay_);
			std::cout << std::flush;
		}
		std::cout << "]" << std::endl;
		printf("\e[?25h");
	}

private:
	int bar_size_ = 30;
	int delay_ {};
	std::string progress_bar_shape_ {};
};

int main()
{
	ProgressBar bar("■");
	bar.update();
	return 0;
}


