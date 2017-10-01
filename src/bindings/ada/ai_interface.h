#ifndef AI_INTERFACE_H
#define AI_INTERFACE_H

int Get_Path_Size(char * pid_);

char ** Get_Path(char * pid_);

bool Find(
	char * pid_,
	char * source_,
	char * destination_,
	int algorithm_);

bool Init(
	char * pid_,
	char * data_path_,
	char * f_name_prefix_,
	char * f_extension_);

bool Finalize();

#endif /*AI_INTERFACE_H*/