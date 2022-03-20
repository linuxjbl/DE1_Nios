
module nios2e (
	clk_clk,
	decode0_external_connection_export,
	period0_external_connection_export,
	reset_reset_n,
	hex0_external_connection_export,
	push_external_connection_export);	

	input		clk_clk;
	output	[27:0]	decode0_external_connection_export;
	output	[27:0]	period0_external_connection_export;
	input		reset_reset_n;
	output	[7:0]	hex0_external_connection_export;
	input	[3:0]	push_external_connection_export;
endmodule
