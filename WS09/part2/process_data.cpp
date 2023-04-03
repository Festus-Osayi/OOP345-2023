// Workshop 9 - Multi-Threading, Thread Class
// process_data.cpp
// 2021/1/5 - Jeevan Pant

/*Filename: process_data.cpp
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/03/19
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete the workshop.*/

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include <vector>
#include "process_data.h"


using namespace std;

namespace sdds_ws9
{
	 
	
	void computeAvgFactor(const int *arr, int size, int divisor, double &avg)
	{
		avg = 0;
		for (int i = 0; i < size; i++)
		{
			avg += arr[i];
		}
		avg /= divisor;
	}

	void computeVarFactor(const int *arr, int size, int divisor, double avg, double &var)
	{
		var = 0;
		for (int i = 0; i < size; i++)
		{
			var += (arr[i] - avg) * (arr[i] - avg);
		}
		var /= divisor;
	}
	ProcessData::operator bool() const
	{
		return total_items > 0 && data && num_threads > 0 && averages && variances && p_indices;
	}


	ProcessData::ProcessData(std::string filename, int n_threads)
	{
		// TODO: Open the file whose name was received as parameter and read the content
		//         into variables "total_items" and "data". Don't forget to allocate
		//         memory for "data".
		//       The file is binary and has the format described in the specs.
		std::ifstream file(filename, std::ios::binary);
		if (!file.is_open())
		{
			std::cout << "Error: failed to open file " << filename << std::endl;
			return;
		}

		file.read(reinterpret_cast<char *>(&total_items), sizeof(total_items));
		if (file.eof())
		{
			std::cerr << "unexpected end of file while reading the total_items on the inut stream." << std::endl;
			return;
		}

		data = new int[total_items];

		file.read(reinterpret_cast<char *>(data), total_items * sizeof(int));
		if (file.eof())
		{
			cout << "an unexpected error occured, unable to read from file." << std::endl;
			delete[] data;
			data = nullptr;
			return;
		}
		
		std::cout << "Item's count in file '" << filename << "': " << total_items << std::endl;
		std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
				  << data[total_items - 3] << ", " << data[total_items - 2] << ", "
				  << data[total_items - 1] << "]\n";
		

		// Following statements initialize the variables added for multi-threaded
		//   computation
		num_threads = n_threads;
		averages = new double[num_threads]{};
		variances = new double[num_threads]{};
		p_indices = new int[num_threads + 1]{};
		
		for (int i = 0; i < num_threads + 1; i++)
			p_indices[i] = i * (total_items / num_threads);

		
	}
	ProcessData::~ProcessData()
	{
		delete[] data;
		delete[] averages;
		delete[] variances;
		delete[] p_indices;
	}

	// TODO Improve operator() function from part-1 for multi-threaded operation. Enhance the
	//   function logic for the computation of average and variance by running the
	//   function computeAvgFactor and computeVarFactor in multiple threads.
	// The function divides the data into a number of parts, where the number of parts is
	//   equal to the number of threads. Use multi-threading to compute average-factor for
	//   each part of the data by calling the function computeAvgFactor. Add the obtained
	//   average-factors to compute total average. Use the resulting total average as the
	//   average value argument for the function computeVarFactor, to compute variance-factors
	//   for each part of the data. Use multi-threading to compute variance-factor for each
	//   part of the data. Add computed variance-factors to obtain total variance.
	// Save the data into a file with filename held by the argument fname_target.
	// Also, read the workshop instruction.
	int ProcessData::operator()(std::string fname_target, double &avg, double &var)
	{
		// Compute average
		avg = 0;
		for (int i = 0; i < total_items; i++)
		{
			avg += data[i];
		}
		avg /= total_items;

		// Compute variance
		var = 0;
		for (int i = 0; i < total_items; i++)
		{
			var += (data[i] - avg) * (data[i] - avg);
		}
		var /= total_items;

		// Save data to file
		std::ofstream outfile(fname_target, std::ios::binary);
		if (!outfile.is_open())
		{
			return -1;
		}

		outfile.write(reinterpret_cast<char *>(&total_items), sizeof(total_items));
		for (int i = 0; i < total_items; i++)
		{
			outfile.write(reinterpret_cast<char *>(&data[i]), sizeof(data[i]));
		}

		outfile.close();

		return 0;
	}
}