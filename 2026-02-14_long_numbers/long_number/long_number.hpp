// long_number.hpp
#pragma once

#include <iostream>

namespace NovSev {
	class LongNumber {
		private:
			int* numbers;
			int length;
			int sign;
		
		public:
			LongNumber();
			LongNumber(int length, int sign);
			LongNumber(const char* const str);
			LongNumber(const LongNumber& x);
			LongNumber(LongNumber&& x) noexcept;  // 🔧 Добавлено noexcept
			
			~LongNumber();
			
			LongNumber& operator = (const char* const str);
			LongNumber& operator = (const LongNumber& x);
			LongNumber& operator = (LongNumber&& x) noexcept;  // 🔧 Добавлено noexcept
			
			bool operator == (const LongNumber& x) const;
			bool operator != (const LongNumber& x) const;
			bool operator > (const LongNumber& x) const;
			bool operator < (const LongNumber& x) const;
			
			LongNumber operator + (const LongNumber& x) const;
			LongNumber operator - (const LongNumber& x) const;
			LongNumber operator * (const LongNumber& x) const;
			LongNumber operator / (const LongNumber& x) const;
			LongNumber operator % (const LongNumber& x) const;
			
			bool is_negative() const noexcept;
			
			friend std::ostream& operator << (std::ostream &os, const LongNumber& x);
			
			// Дружественные функции для деления
			friend bool is_abs_greater_or_equal(const LongNumber& a, const LongNumber& b);
			friend void subtract_abs(LongNumber& a, const LongNumber& b);
			
		private:
			int get_length(const char* const str) const noexcept;
	};
}