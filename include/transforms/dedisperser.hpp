#pragma once
#include "dedisp.h"
#include <vector>
#include <string>
#include <data_types/timeseries.hpp>
#include <data_types/filterbank.hpp>

class Dedisperser {
private:
  dedisp_plan plan;
  SigprocFilterbank& filterbank;
  unsigned int num_gpus;
  std::vector<float> dm_list;
  std::vector<dedisp_bool> killmask;
  static void check_dedisp_error(dedisp_error error,
			  std::string function_name);

public:
  Dedisperser(SigprocFilterbank& filterbank, unsigned int num_gpus=1);
  void set_dm_list(float* dm_list, unsigned int ndms);
  void set_dm_list(std::vector<float> dm_list);
  std::vector<float> get_dm_list(void);
  void generate_dm_list(float dm_start, float dm_end,
			float width, float tolerance);
  void set_killmask(std::vector<int> killmask);
  void set_killmask(std::string killmaskfile);
  DispersionTrials<unsigned char> dedisperse(void);
  

};