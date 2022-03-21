
module nios2e (
	clk_clk,
	decode0_external_connection_export,
	hex0_external_connection_export,
	period0_external_connection_export,
	push_external_connection_export,
	reset_reset_n,
	period1_external_connection_export,
	period2_external_connection_export,
	period3_external_connection_export,
	period4_external_connection_export,
	period5_external_connection_export,
	period6_external_connection_export,
	period7_external_connection_export,
	decode1_external_connection_export,
	decode2_external_connection_export,
	decode3_external_connection_export,
	decode4_external_connection_export,
	decode5_external_connection_export,
	decode6_external_connection_export,
	decode7_external_connection_export);	

	input		clk_clk;
	output	[27:0]	decode0_external_connection_export;
	output	[7:0]	hex0_external_connection_export;
	output	[27:0]	period0_external_connection_export;
	input	[3:0]	push_external_connection_export;
	input		reset_reset_n;
	output	[27:0]	period1_external_connection_export;
	output	[27:0]	period2_external_connection_export;
	output	[27:0]	period3_external_connection_export;
	output	[27:0]	period4_external_connection_export;
	output	[27:0]	period5_external_connection_export;
	output	[27:0]	period6_external_connection_export;
	output	[27:0]	period7_external_connection_export;
	output	[27:0]	decode1_external_connection_export;
	output	[27:0]	decode2_external_connection_export;
	output	[27:0]	decode3_external_connection_export;
	output	[27:0]	decode4_external_connection_export;
	output	[27:0]	decode5_external_connection_export;
	output	[27:0]	decode6_external_connection_export;
	output	[27:0]	decode7_external_connection_export;
endmodule
