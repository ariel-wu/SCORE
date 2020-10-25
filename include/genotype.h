#ifndef GENOTYPE_H
#define GENOTYPE_H
#include <bits/stdc++.h>
#include "storage.h"
#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/LU>
#include <Eigen/SVD>


class genotype {
	std::vector< std::vector <bool> > msb;
	std::vector< std::vector <bool> > lsb;
	std::vector< std::vector <int> > columnsum;
	std::vector< std::vector <int> > columnsum2;
	std::vector< std::vector <double> > columnmeans;
	std::vector<double> columnmeans2;
	int chromSNP[23]; 
	std::vector< std::vector <double> > rowsum; 	
	public:	

		unsigned char mask;
    	int wordsize;
	    unsigned int unitsperword;
    	int unitsize;
	 	int nrow, ncol;
		unsigned char *gtype;

		int Nsnp,Nindv,Nsegments_hori,segment_size_hori,segment_size_ver,Nsegments_ver;
		int Nbits_hori,Nbits_ver;
		int Nelements_hori,Nelements_ver;
		std::vector< std::vector<int> > p;

		// std::vector< std::vector<unsigned> > p_eff;
		// std::vector< std::vector<unsigned> > q_eff;

		std::vector< std::vector<int> > not_O_j;
		std::vector< std::vector<int> > not_O_i;
		
		void init_means(bool is_missing, int pheno_num, Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> &exist_ind, int snp_idx);

		float get_observed_pj(const std::string &line); 
		float get_observed_pj(const unsigned char* line); 

		void read_txt_naive(std::string filename,bool allow_missing);
		
		void read_txt_mailman (std::string filename,bool allow_missing);

		void read_plink (std::string filenameprefix, bool allow_missing,bool mailman_mode,Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> &pheno_mask, int pheno_num);
		void read_bed (std::string filename, bool allow_missing, bool mailman_mode ,Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> &pheno_mask, int pheno_num)  ;
		void read_bed_mailman (std::string filename,bool allow_missing ,Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> &pheno_mask, int pheno_num)  ;
		void read_bed_naive (std::string filename ,bool allow_missing, Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> &pheno_mask, int pheno_num)  ;
		void read_bed_mailman_stream (std::string filename, bool allow_missing, Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>  &pheno_mask, int pheno_num, int snp_idx, std::ifstream & ifs, int SNP_BLOCK_SIZE); 	
		void read_fam (std::string filename )  ;
		void read_bim (std::string filename , int pheno_num)  ;
		void set_metadata () ;


		double get_geno(int snpindex,int indvindex,bool var_normalize, int phenoindex, int exist_ind);
		double get_col_mean(int snpindex, int phenoindex);
		double get_col_sum(int snpindex, int phenoindex);		
		double get_row_sum(int indeindex, int chromindex); 
		double get_col_sum2(int snpindes, int phenoindex); 
		double get_col_std(int snpindex, int phenoindex, int exist_ind);	
		int get_chrom_snp(int chromindex); 	
		void update_col_mean(int snpindex,double value, int phenoindex);

		void generate_eigen_geno(Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> &geno_matrix,bool var_normalize, int phenoindex);

		void clear_vectors(); 	
};

#endif
