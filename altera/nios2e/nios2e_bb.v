
module nios2e (
	clk_clk,
	decode0_external_connection_export,
	reset_reset_n,
	period0_external_connection_export);	

	input		clk_clk;
	output	[27:0]	decode0_external_connection_export;
	input		reset_reset_n;
	output	[27:0]	period0_external_connection_export;
endmodule
