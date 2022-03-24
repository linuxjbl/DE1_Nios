module PwmCtrl (
	RST_N,
	CLK,
	LED,
	HEX0,
	HEX1,
	HEX2,
	HEX3,
	HEX4,
	HEX5,
	PUSH,
    DRAM_ADDR,   // new_sdram_controller_0_wire.addr
    DRAM_BA,     //                            .ba
	DRAM_CAS_N,  //                            .cas_n
	DRAM_CKE,    //                            .cke
	DRAM_CS_N,   //                            .cs_n
	DRAM_DQ,     //                            .dq
	DRAM_DQM,    //                            .dqm
	DRAM_RAS_N,  //                            .ras_n
	DRAM_WE_N    //    
 ); 

input		CLK, RST_N;
output		[9:0] LED;
output		[6:0] HEX0;
output		[6:0] HEX1;
output		[6:0] HEX2;
output		[6:0] HEX3;
output		[6:0] HEX4;
output		[6:0] HEX5;
input		[3:0] PUSH;
output      [12:0]  DRAM_ADDR;   // new_sdram_controller_0_wire.addr
output      [1:0]   DRAM_BA;     //                            .ba
output	            DRAM_CAS_N;  //                            .cas_n
output	            DRAM_CKE;    //                            .cke
output	            DRAM_CS_N;   //                            .cs_n
inout	    [15:0]  DRAM_DQ;     //                            .dq
output	    [1:0]   DRAM_DQM;    //                            .dqm
output	            DRAM_RAS_N;  //                            .ras_n
output	            DRAM_WE_N;    //    

reg [27:0]	counter0;
wire 		counter0_clr, counter0_dec;
wire [27:0] Decode0;
wire [27:0] Period0;


reg [27:0]	counter1;
wire 			counter1_clr, counter1_dec;
wire [27:0] Decode1;
wire [27:0] Period1;

reg [27:0]	counter2;
wire 			counter2_clr, counter2_dec;
wire [27:0] Decode2;
wire [27:0] Period2;

reg [27:0]	counter3;
wire 			counter3_clr, counter3_dec;
wire [27:0] Decode3;
wire [27:0] Period3;

reg [27:0]	counter4;
wire 			counter4_clr, counter4_dec;
wire [27:0] Decode4;
wire [27:0] Period4;

reg [27:0]	counter5;
wire 			counter5_clr, counter5_dec;
wire [27:0] Decode5;
wire [27:0] Period5;

reg [27:0]	counter6;
wire 			counter6_clr, counter6_dec;
wire [27:0] Decode6;
wire [27:0] Period6;

reg [27:0]	counter7;
wire 			counter7_clr, counter7_dec;
wire [27:0] Decode7;
wire [27:0] Period7;


assign LED[0] = counter0_dec;
assign LED[1] = counter1_dec;
assign LED[2] = counter2_dec;
assign LED[3] = counter3_dec;
assign LED[4] = counter4_dec;
assign LED[5] = counter5_dec;
assign LED[6] = counter6_dec;
assign LED[7] = counter7_dec;
assign LED[8] = ~counter0_dec;
assign LED[9] = ~counter1_dec;


/////////////////////////////////////////////
// for PWM0
always @(negedge RST_N or posedge CLK)
begin
	if (RST_N == 1'b0) begin
		counter0 <= 0;
	end else begin
		if(counter0_clr == 1'b1) begin
			counter0 <= 0;
		end else begin
			counter0 <= counter0 + 1;
		end
	end
end

assign counter0_clr = (counter0 >= Period0-1) ? 1'b1 : 1'b0;
assign counter0_dec = (counter0 < Decode0) ? 1'b1 : 1'b0;

/////////////////////////////////////////////
// for PWM1
always @(negedge RST_N or posedge CLK)
begin
	if (RST_N == 1'b0) begin
		counter1 <= 0;
	end else begin
		if(counter1_clr == 1'b1) begin
			counter1 <= 0;
		end else begin
			counter1 <= counter1 + 1;
		end
	end
end

assign counter1_clr = (counter1 >= Period1-1) ? 1'b1 : 1'b0;
assign counter1_dec = (counter1 < Decode1) ? 1'b1 : 1'b0;

/////////////////////////////////////////////
// for PWM2
always @(negedge RST_N or posedge CLK)
begin
	if (RST_N == 1'b0) begin
		counter2 <= 0;
	end else begin
		if(counter2_clr == 1'b1) begin
			counter2 <= 0;
		end else begin
			counter2 <= counter2 + 1;
		end
	end
end

assign counter2_clr = (counter2 >= Period2-1) ? 1'b1 : 1'b0;
assign counter2_dec = (counter2 < Decode2) ? 1'b1 : 1'b0;

/////////////////////////////////////////////
// for PWM3
always @(negedge RST_N or posedge CLK)
begin
	if (RST_N == 1'b0) begin
		counter3 <= 0;
	end else begin
		if(counter3_clr == 1'b1) begin
			counter3 <= 0;
		end else begin
			counter3 <= counter3 + 1;
		end
	end
end

assign counter3_clr = (counter3 >= Period3-1) ? 1'b1 : 1'b0;
assign counter3_dec = (counter3 < Decode3) ? 1'b1 : 1'b0;

/////////////////////////////////////////////
// for PWM4
always @(negedge RST_N or posedge CLK)
begin
	if (RST_N == 1'b0) begin
		counter4 <= 0;
	end else begin
		if(counter4_clr == 1'b1) begin
			counter4 <= 0;
		end else begin
			counter4 <= counter4 + 1;
		end
	end
end

assign counter4_clr = (counter4 >= Period4-1) ? 1'b1 : 1'b0;
assign counter4_dec = (counter4 < Decode4) ? 1'b1 : 1'b0;

/////////////////////////////////////////////
// for PWM5
always @(negedge RST_N or posedge CLK)
begin
	if (RST_N == 1'b0) begin
		counter5 <= 0;
	end else begin
		if(counter5_clr == 1'b1) begin
			counter5 <= 0;
		end else begin
			counter5 <= counter5 + 1;
		end
	end
end

assign counter5_clr = (counter5 >= Period5-1) ? 1'b1 : 1'b0;
assign counter5_dec = (counter5 < Decode5) ? 1'b1 : 1'b0;

/////////////////////////////////////////////
// for PWM6
always @(negedge RST_N or posedge CLK)
begin
	if (RST_N == 1'b0) begin
		counter6 <= 0;
	end else begin
		if(counter6_clr == 1'b1) begin
			counter6 <= 0;
		end else begin
			counter6 <= counter6 + 1;
		end
	end
end

assign counter6_clr = (counter6 >= Period6-1) ? 1'b1 : 1'b0;
assign counter6_dec = (counter6 < Decode6) ? 1'b1 : 1'b0;

/////////////////////////////////////////////
// for PWM7
always @(negedge RST_N or posedge CLK)
begin
	if (RST_N == 1'b0) begin
		counter7 <= 0;
	end else begin
		if(counter7_clr == 1'b1) begin
			counter7 <= 0;
		end else begin
			counter7 <= counter7 + 1;
		end
	end
end

assign counter7_clr = (counter7 >= Period7-1) ? 1'b1 : 1'b0;
assign counter7_dec = (counter7 < Decode7) ? 1'b1 : 1'b0;




    nios2e u0 (
        .clk_clk                            (CLK),  
        .reset_reset_n                      (RST_N),  
        .period0_external_connection_export (Period0), 
        .decode0_external_connection_export (Decode0),
        .period1_external_connection_export (Period1), 
        .decode1_external_connection_export (Decode1),
        .period2_external_connection_export (Period2), 
        .decode2_external_connection_export (Decode2),
        .period3_external_connection_export (Period3), 
        .decode3_external_connection_export (Decode3),
        .period4_external_connection_export (Period4), 
        .decode4_external_connection_export (Decode4),
        .period5_external_connection_export (Period5), 
        .decode5_external_connection_export (Decode5),
        .period6_external_connection_export (Period6), 
        .decode6_external_connection_export (Decode6),
        .period7_external_connection_export (Period7), 
        .decode7_external_connection_export (Decode7),
        .hex0_external_connection_export    ({HEX5[0], HEX0[6:0]}), 
        .hex1_external_connection_export    ({HEX5[1], HEX1[6:0]}), 
        .hex2_external_connection_export    ({HEX5[2], HEX2[6:0]}), 
        .hex3_external_connection_export    ({HEX5[3], HEX3[6:0]}), 
        .hex4_external_connection_export    (), 
        .hex5_external_connection_export    (), 
        .push_external_connection_export    (PUSH[1:0]),
        .new_sdram_controller_0_wire_addr   (DRAM_ADDR),   // new_sdram_controller_0_wire.addr
		.new_sdram_controller_0_wire_ba     (DRAM_BA),     //                            .ba
		.new_sdram_controller_0_wire_cas_n  (DRAM_CAS_N),  //                            .cas_n
		.new_sdram_controller_0_wire_cke    (DRAM_CKE),    //                            .cke
		.new_sdram_controller_0_wire_cs_n   (DRAM_CS_N),   //                            .cs_n
		.new_sdram_controller_0_wire_dq     (DRAM_DQ),     //                            .dq
		.new_sdram_controller_0_wire_dqm    (DRAM_DQM),    //                            .dqm
		.new_sdram_controller_0_wire_ras_n  (DRAM_RAS_N),  //                            .ras_n
		.new_sdram_controller_0_wire_we_n   (DRAM_WE_N)    //                            .we_n
 
 
    );

endmodule
