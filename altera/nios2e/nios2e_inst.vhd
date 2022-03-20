	component nios2e is
		port (
			clk_clk                            : in  std_logic                     := 'X';             -- clk
			decode0_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			period0_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			reset_reset_n                      : in  std_logic                     := 'X';             -- reset_n
			hex0_external_connection_export    : out std_logic_vector(7 downto 0);                     -- export
			push_external_connection_export    : in  std_logic_vector(3 downto 0)  := (others => 'X')  -- export
		);
	end component nios2e;

	u0 : component nios2e
		port map (
			clk_clk                            => CONNECTED_TO_clk_clk,                            --                         clk.clk
			decode0_external_connection_export => CONNECTED_TO_decode0_external_connection_export, -- decode0_external_connection.export
			period0_external_connection_export => CONNECTED_TO_period0_external_connection_export, -- period0_external_connection.export
			reset_reset_n                      => CONNECTED_TO_reset_reset_n,                      --                       reset.reset_n
			hex0_external_connection_export    => CONNECTED_TO_hex0_external_connection_export,    --    hex0_external_connection.export
			push_external_connection_export    => CONNECTED_TO_push_external_connection_export     --    push_external_connection.export
		);

