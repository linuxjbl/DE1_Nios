	component nios2e is
		port (
			clk_clk                            : in  std_logic                     := 'X';             -- clk
			decode0_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			decode1_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			decode2_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			decode3_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			decode4_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			decode5_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			decode6_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			decode7_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			hex0_external_connection_export    : out std_logic_vector(7 downto 0);                     -- export
			period0_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			period1_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			period2_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			period3_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			period4_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			period5_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			period6_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			period7_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			push_external_connection_export    : in  std_logic_vector(3 downto 0)  := (others => 'X'); -- export
			reset_reset_n                      : in  std_logic                     := 'X';             -- reset_n
			hex1_external_connection_export    : out std_logic_vector(7 downto 0);                     -- export
			hex2_external_connection_export    : out std_logic_vector(7 downto 0);                     -- export
			hex3_external_connection_export    : out std_logic_vector(7 downto 0);                     -- export
			hex4_external_connection_export    : out std_logic_vector(7 downto 0);                     -- export
			hex5_external_connection_export    : out std_logic_vector(7 downto 0)                      -- export
		);
	end component nios2e;

	u0 : component nios2e
		port map (
			clk_clk                            => CONNECTED_TO_clk_clk,                            --                         clk.clk
			decode0_external_connection_export => CONNECTED_TO_decode0_external_connection_export, -- decode0_external_connection.export
			decode1_external_connection_export => CONNECTED_TO_decode1_external_connection_export, -- decode1_external_connection.export
			decode2_external_connection_export => CONNECTED_TO_decode2_external_connection_export, -- decode2_external_connection.export
			decode3_external_connection_export => CONNECTED_TO_decode3_external_connection_export, -- decode3_external_connection.export
			decode4_external_connection_export => CONNECTED_TO_decode4_external_connection_export, -- decode4_external_connection.export
			decode5_external_connection_export => CONNECTED_TO_decode5_external_connection_export, -- decode5_external_connection.export
			decode6_external_connection_export => CONNECTED_TO_decode6_external_connection_export, -- decode6_external_connection.export
			decode7_external_connection_export => CONNECTED_TO_decode7_external_connection_export, -- decode7_external_connection.export
			hex0_external_connection_export    => CONNECTED_TO_hex0_external_connection_export,    --    hex0_external_connection.export
			period0_external_connection_export => CONNECTED_TO_period0_external_connection_export, -- period0_external_connection.export
			period1_external_connection_export => CONNECTED_TO_period1_external_connection_export, -- period1_external_connection.export
			period2_external_connection_export => CONNECTED_TO_period2_external_connection_export, -- period2_external_connection.export
			period3_external_connection_export => CONNECTED_TO_period3_external_connection_export, -- period3_external_connection.export
			period4_external_connection_export => CONNECTED_TO_period4_external_connection_export, -- period4_external_connection.export
			period5_external_connection_export => CONNECTED_TO_period5_external_connection_export, -- period5_external_connection.export
			period6_external_connection_export => CONNECTED_TO_period6_external_connection_export, -- period6_external_connection.export
			period7_external_connection_export => CONNECTED_TO_period7_external_connection_export, -- period7_external_connection.export
			push_external_connection_export    => CONNECTED_TO_push_external_connection_export,    --    push_external_connection.export
			reset_reset_n                      => CONNECTED_TO_reset_reset_n,                      --                       reset.reset_n
			hex1_external_connection_export    => CONNECTED_TO_hex1_external_connection_export,    --    hex1_external_connection.export
			hex2_external_connection_export    => CONNECTED_TO_hex2_external_connection_export,    --    hex2_external_connection.export
			hex3_external_connection_export    => CONNECTED_TO_hex3_external_connection_export,    --    hex3_external_connection.export
			hex4_external_connection_export    => CONNECTED_TO_hex4_external_connection_export,    --    hex4_external_connection.export
			hex5_external_connection_export    => CONNECTED_TO_hex5_external_connection_export     --    hex5_external_connection.export
		);

