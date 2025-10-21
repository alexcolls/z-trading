# 📊 Trading Algorithms & Strategies

## Overview

The Z-Trading framework includes **326 C trading strategies** and **36 Python utilities** covering a wide range of algorithmic trading approaches. These strategies span from simple educational examples to sophisticated multi-asset portfolio systems with machine learning integration.

All C strategies are located in the `algos/` directory and can be run directly through the Zorro trading engine. Python utilities provide data analysis, risk management, live monitoring, and broker API integration.

---

## Table of Contents

1. [Strategy Categories](#strategy-categories)
2. [Alice Series - Trend & ML Strategies](#alice-series)
3. [Trend Following Strategies](#trend-following-strategies)
4. [G12 Currency Strength System](#g12-currency-strength-system)
5. [COT (Commitments of Traders)](#cot-commitments-of-traders)
6. [Workshop Educational Series](#workshop-educational-series)
7. [FX Market Making Strategies](#fx-market-making-strategies)
8. [Options Trading Strategies](#options-trading-strategies)
9. [Cryptocurrency Strategies](#cryptocurrency-strategies)
10. [Economic Data Strategies](#economic-data-strategies)
11. [Pattern Recognition & Image](#pattern-recognition--image)
12. [Portfolio Management](#portfolio-management)
13. [Specialized Strategies](#specialized-strategies)
14. [Python Utilities](#python-utilities)

---

## Strategy Categories

### Summary Statistics

| Category | Count | Description |
|----------|-------|-------------|
| **Alice Series** | 13 | Trend detection, counter-trend, portfolio, and ML strategies |
| **Trend Following** | 13 | Various trend detection filters (ALMA, EMA, HMA, Laguerre, etc.) |
| **G12 Family** | 11 | Currency strength and cross-pair trading systems |
| **COT Strategies** | 14 | Commitment of Traders report-based systems |
| **Workshop Series** | 9 | Educational step-by-step trading system development |
| **FX Market Making** | 6 | High-frequency forex market making strategies |
| **Options** | 6 | Options pricing, Greeks calculation, and combo strategies |
| **Economic Data** | 15 | Fundamental analysis and economic indicator trading |
| **Image/Pattern** | 10 | Pattern recognition and visual chart analysis |
| **Cryptocurrency** | 2+ | Digital asset trading strategies |
| **Other Specialized** | 227+ | Custom indicators, tools, and proprietary systems |

---

## Alice Series

The **Alice** series represents a progressive learning path from basic trend following to advanced machine learning systems.

### Alice 1: Basic Trend Following

**Alice1a.c** & **Alice1b.c**
- Simple trend detection using LowPass filter
- Entry on peaks and valleys
- ATR-based stop loss
- EUR/USD optimized

```c
// Core Logic:
vars Trend = series(LowPass(Price, 500));
if(valley(Trend)) enterLong();
else if(peak(Trend)) enterShort();
Stop = 4*ATR(100);
```

### Alice 2: Counter-Trend Trading

**Alice2a.c**, **Alice2b.c**, **Alice2c.c**, **Alice2d.c**
- Mean reversion strategies
- RSI-based entry signals
- Optimized thresholds
- Workshop 5 implementations

### Alice 3: Portfolio Trading

**Alice3a.c** & **Alice3b.c**
- Multi-asset portfolio management
- Three capital allocation methods:
  1. Fixed 1% balance allocation
  2. 50% of Optimal-F
  3. Square root of component profit
- Diversified risk across instruments

### Alice 4: Machine Learning

**Alice4a.c**, **Alice4a_2.c**, **Alice4b.c**
- Neural network pattern recognition
- Machine learning signal generation
- Perceptron and decision tree models
- Keras/TensorFlow integration

### Alice 5: Advanced Systems

**Alice5a.c** - Scam Robot Detection
- Demonstrates poor risk management (educational)
- 500 pip stops to avoid granularity bias
- Shows how NOT to trade

**Alice5b.c** - Martingale System
- Demonstrates dangerous position sizing (educational)
- Used to illustrate risk of ruin concepts

---

## Trend Following Strategies

The **Trend** family implements various filtering techniques for trend detection.

### Core Trend Strategies

| Strategy | Filter Type | Description |
|----------|-------------|-------------|
| **TrendSMA.c** | Simple Moving Average | Classic moving average crossover |
| **TrendEMA.c** | Exponential Moving Average | Responsive trend following |
| **TrendHMA.c** | Hull Moving Average | Reduced lag trend filter |
| **TrendALMA.c** | Arnaud Legoux Moving Average | Gaussian-weighted filter |
| **TrendLaguerre.c** | Laguerre Filter | Phase-neutral smoothing |
| **TrendLowPass.c** | Low-Pass Filter | Signal processing approach |
| **TrendZMA.c** | Zero-Lag Moving Average | Predictive trend estimation |
| **TrendMMI.c** | Market Meanness Index | Trend strength measurement |
| **TrendLinearReg.c** | Linear Regression | Statistical trend line |
| **TrendSmooth.c** | Smoothing Filter | Noise reduction |
| **TrendDecycle.c** | Ehlers Decycler | Cycle component removal |
| **TrendCounter.c** | Counter Trend | Mean reversion variant |

### Advanced Implementations

**Trend.c** - Base trend framework
**ZLMAtrend.c** - Zero-Lag moving average implementation
**ZigZag.c**, **ZigZag2.c**, **ZigZag3.c** - Swing high/low detection

---

## G12 Currency Strength System

The **G12** series trades based on relative currency strength across the G10+ currencies.

### Concept

Calculates individual currency returns by aggregating all cross-pair movements:
- Tracks 12 currencies: AUD, CAD, CHF, EUR, GBP, HKD, JPY, NZD, SGD, USD, XAG, XAU
- Computes currency strength indices
- Trades divergences between strong/weak currencies

### Strategies

| Strategy | Focus | Description |
|----------|-------|-------------|
| **G12.c** | Core System | Multi-currency strength calculation |
| **G12_EURUSD.c** | EUR/USD | Optimized for major pair |
| **G12_GBPUSD.c** | GBP/USD | Cable-specific tuning |
| **G12_AUDUSD.c** | AUD/USD | Aussie dollar focus |
| **G12_AUDCAD.c** | AUD/CAD | Commodity currency cross |
| **G12_AUDCHF.c** | AUD/CHF | Safe haven divergence |
| **G12_EURAUD.c** | EUR/AUD | Cross-regional strength |
| **G12_GBPJPY.c** | GBP/JPY | High volatility pair |
| **G12x.c** | Extended | Additional asset coverage |

### Implementation Details

```c
// Currency return calculation
#define R log(price(0))-log(price(1))

// Aggregate returns across all pairs
asset("EUR/USD"); r = R; EUR += r; USD -= r;
asset("GBP/USD"); r = R; GBP += r; USD -= r;
// ... continues for all pairs

// Apply filters
double EURf = LowPass(series(EUR), 200);
double USDf = LowPass(series(USD), 200);

// Generate signals
if(EUR > EURf + threshold && USD < USDf - threshold)
    enterLong(); // Buy EUR/USD
```

---

## COT (Commitments of Traders)

The **COT** series uses CFTC Commitments of Traders reports to gauge market positioning.

### Available Strategies

**COT.c** through **COT11.c** - Core COT implementations
- Commercial hedger positioning
- Large speculator sentiment
- Non-commercial net positions
- Fast and slow COT indices

**COTstrat1.c**, **COTstrat2.c**, **COTstrat3.c** - Trading strategies
- COT-based entry signals
- Contrarian positioning
- Trend confirmation

### Data Sources

- CFTC Commitments of Traders reports (weekly)
- Quandl COT data integration
- Commercial index calculations
- Historical positioning analysis

### Example Usage

```c
// Gold COT analysis
string COT_Code = "CFTC/088691_F_ALL";
var Ind = COT_CommercialIndex(1, COT_Code, 6*20);  // Fast
var Ind2 = COT_CommercialIndex(1, COT_Code, 12*20); // Slow

// Trade on divergence
if(crossOver(Ind, Ind2)) enterLong();
```

---

## Workshop Educational Series

The **Workshop** series provides step-by-step strategy development tutorials.

| Workshop | Topic | Key Concepts |
|----------|-------|--------------|
| **Workshop1.c** | Introduction | Basic strategy structure |
| **Workshop2.c** | Indicators | Technical analysis integration |
| **Workshop3.c** | Entry Logic | Signal generation |
| **Workshop4.c** | Risk Management | Stop loss and position sizing |
| **Workshop5.c** | Counter-Trend | Mean reversion techniques |
| **Workshop6.c** | Portfolio | Multi-asset management |
| **Workshop7.c** | Optimization | Parameter tuning |
| **Workshop8.c** | Walk-Forward | Robust testing methods |

---

## FX Market Making Strategies

High-frequency market making strategies for forex pairs.

### Strategies

**FXmarketmaking1.c** through **FXmarketmaking6.c**
- Intraday market making
- Bid-ask spread capture
- Session-based trading (London/NY)
- Weekly high/low range systems
- Low-pass filter for trend detection
- Hedged positioning

### Features

- 1-minute bar execution
- Spread and commission modeling set to zero (for HFT simulation)
- Virtual hedging for simultaneous long/short
- Dynamic position sizing based on volatility
- Trading session filters (Monday-Thursday, specific hours)

### Implementation Highlights

```c
// Market making logic
if(priceHigh(0) > MidWeek && side < 0)
    enterShort(Sizes, -priceHigh(0));
if(priceLow(0) < MidWeek && side > 0)
    enterLong(Sizes, -priceLow(0));
```

---

## Options Trading Strategies

Options pricing, Greeks calculation, and volatility trading.

### Available Strategies

| Strategy | Description |
|----------|-------------|
| **OptionsSimple.c** | Basic options trading |
| **OptionsCalculator.c** | Greeks and IV calculation |
| **OptionsCurve.c** | Volatility smile analysis |
| **OptionsCurve2.c** | Term structure analysis |
| **OptionsSimulate.c** | Options strategy backtesting |
| **OptionsSellRandom.c** | Random option selling (educational) |

### Options Features

- Implied volatility calculation
- Greeks: Delta, Gamma, Theta, Vega, Rho
- Multi-leg combo strategies
- Option payoff visualization
- Volatility surface analysis

---

## Cryptocurrency Strategies

Digital asset trading strategies optimized for crypto markets.

### Strategies

**CryptoFac1.c** & **CryptoFac2.c**
- Cryptocurrency factor models
- Multi-coin portfolio strategies
- Volatility-adjusted position sizing

**BTCUSD_v1.c** & **BTCUSD_vol.c**
- Bitcoin-specific strategies
- Volatility breakout systems
- Support for crypto exchanges (Binance, Kraken, Deribit)

---

## Economic Data Strategies

Fundamental analysis and economic indicator-based trading.

### Eco Series

**Eco0.c** through **Eco13.c** & **Economics1.c**
- Economic calendar event trading
- GDP, unemployment, inflation data
- Central bank policy signals
- Yield curve analysis
- Earnings-based stock trading

### Edgar Integration

**Edgar.c**
- SEC EDGAR database integration
- Automated earnings report parsing
- Fundamental data extraction

---

## Pattern Recognition & Image

Chart pattern recognition and visual analysis strategies.

### Image Series

**Image1.c** through **Image10.c**
- Candlestick pattern detection
- Renko bar construction
- Point-and-figure charting
- Support/resistance identification
- Custom bar type implementations

### Pattern Detection

- Frechet distance matching
- Divergence/convergence detection
- Head and shoulders patterns
- Double tops/bottoms
- Triangle formations

---

## Portfolio Management

Multi-asset allocation and portfolio optimization strategies.

### Core Strategies

**Allocation.c**, **Allocation2.c**, **Allocation3.c**
- Mean-Variance Optimization (MVO)
- Optimal-F position sizing
- Risk parity allocation
- Correlation-based diversification

**PortfolioBalancer.c** family
- Dynamic rebalancing
- Momentum rotation
- Sector allocation

---

## Specialized Strategies

Additional specialized trading systems and tools.

### Utility Strategies

| Category | Examples |
|----------|----------|
| **Data Import** | CSVtoHistory.c, CSVtoOptions.c, Download.c |
| **Testing** | Benchmark.c, EquityTest.c, TradeTest.c |
| **Analysis** | Analysis.c, Spectrum.c, AutoCorrel.c |
| **Indicators** | Accelerator.c, Ehlers.c, Filter.c |
| **Regime Detection** | Regime.c, Cycles2.c |
| **Volatility** | VolatilityStrat.c |
| **Spreads** | BrokerArb.c, OandaSpreads family |
| **Volume** | Volume1.c |
| **Sentiment** | Sentiment.c, CurrencyIndex family |
| **Session Analysis** | TradingSessions family |
| **Deep Learning** | DeepLearn.c, DeepSignals.c |

### Custom Systems

**X1.c** through **X15.c** - Experimental strategies
**P1.c** through **P4.c** - Proprietary systems
**S1.c** through **S6.c** - Statistical arbitrage
**R1.c** through **R5.c** - Research implementations

---

## Python Utilities

### Core Trading Utilities

#### TraderDashboard.py
Real-time trading dashboard with Google Sheets integration
- Live account monitoring
- Position tracking
- P&L calculation
- Risk metrics
- Auto-updating Google Sheets

#### RiskManager.py
Advanced risk management system
- Volatility-based position sizing
- Correlation-adjusted exposure
- Portfolio risk monitoring
- Maximum position calculations
- Google Sheets risk reports

#### OandaLib.py
OANDA API wrapper and utilities
- Real-time price streaming
- Historical data fetching
- Order execution
- Position management
- 120+ instrument support
- Google Sheets data export

### Data Analysis Utilities

#### Correlations.py & CorrelationsDB.py
- Cross-asset correlation calculation
- Rolling correlation analysis
- Correlation matrix generation
- MySQL database storage
- Historical correlation trends

#### Volatility.py
- ATR (Average True Range) calculation
- Historical volatility metrics
- Realized vs implied volatility
- Volatility regime detection
- Intraday volatility patterns

#### IntradayATR.py
- Minute-by-minute ATR tracking
- Session-based volatility
- Optimal entry timing
- Spread cost analysis

### Market Data Utilities

**IntradayCorrelation.py** - Real-time correlation tracking
**IntradaySpreads.py** - Bid-ask spread monitoring
**IntradayVolume.py** - Volume profile analysis
**IntraweekVolume.py** - Weekly volume patterns

### OANDA Integration Series

**Oanda1.py** through **Oanda8.py**
- Various OANDA API implementations
- Different data retrieval methods
- Order management approaches
- Testing and development scripts

### Database & Storage

**mysql.py** - MySQL database connector
**OandaEuropeStatsDB.py** - Statistical data storage
**Stats.py** - Performance statistics calculation

### Google Sheets Integration

**GoogleService.py** & **GoogleService2.py**
- Google Sheets API wrapper
- OAuth2 authentication
- Data formatting and upload
- Multi-sheet management

**GSOA_Overview.py** - OANDA account overview dashboard

### Position Management

**Positions.py** - Position tracking and management
**Account.py** - Account information retrieval
**Trader.py**, **Trader1.py**, **Trader6.py** - Trading execution scripts

### Data Processing

**DataFromC.py** - Import data from C strategy output
**Permutation.py** & **Permutation2.py** - Strategy combination testing

---

## Usage Examples

### Running C Strategies

```bash
# Via Zorro GUI
1. Open Zorro.exe
2. Select strategy from dropdown (e.g., Alice1a.c)
3. Choose mode: Trade/Test/Train
4. Click "Run"

# Via command line
Zorro.exe -run Alice1a.c -t -p EUR/USD
```

### Using Python Utilities

```bash
# Real-time trading dashboard
poetry run python algos/TraderDashboard.py

# Risk management analysis
poetry run python algos/RiskManager.py

# Correlation analysis
poetry run python algos/Correlations.py
```

### Integration Example

```python
from algos.OandaLib import Oanda_Prices, Oanda_Candles
from algos.RiskManager import calculate_position_size

# Get live prices
prices = Oanda_Prices(account_id, {'instruments': 'EUR_USD'})

# Fetch historical data
candles = Oanda_Candles('EUR_USD', {'granularity': 'H1', 'count': 500})

# Calculate position size
size = calculate_position_size('EUR_USD', risk_percent=1.0)
```

---

## Strategy Development Workflow

### 1. Research Phase
- Use Analysis.c, Spectrum.c for market research
- Analyze correlations with Correlations.py
- Study volatility patterns with Volatility.py

### 2. Development Phase
- Start with Workshop series for learning
- Prototype in C using Zorro editor
- Test indicators and signals

### 3. Backtesting Phase
- Use Zorro's backtesting engine
- Run walk-forward optimization
- Analyze with Monte Carlo methods

### 4. Paper Trading Phase
- Deploy with TraderDashboard.py monitoring
- Track with RiskManager.py
- Log all trades for analysis

### 5. Live Trading Phase
- Start with small position sizes
- Monitor via Google Sheets dashboards
- Continuous risk management

---

## Performance Optimization

### Strategy Optimization Tips

1. **Parameter Optimization**
   - Use Zorro's genetic algorithms
   - Walk-forward analysis for robustness
   - Avoid over-fitting with WFO cycles

2. **Execution Speed**
   - Compile C strategies for maximum performance
   - Use TICKS mode for HFT strategies
   - Minimize indicator calculations

3. **Risk Management**
   - Always use RiskManager.py for position sizing
   - Monitor correlations between strategies
   - Diversify across timeframes and assets

4. **Data Quality**
   - Verify historical data accuracy
   - Account for spread and slippage
   - Use realistic commission models

---

## Strategy Selection Guide

### For Beginners
- **Workshop Series** - Learn fundamentals
- **Alice1a/1b** - Simple trend following
- **TrendSMA** - Classic moving average system

### For Intermediate Traders
- **Alice2 Series** - Counter-trend strategies
- **Alice3 Series** - Portfolio management
- **G12 Family** - Currency strength systems

### For Advanced Traders
- **Alice4 Series** - Machine learning integration
- **FX Market Making** - High-frequency strategies
- **Options Strategies** - Derivatives trading
- **COT Strategies** - Fundamental positioning

### For Researchers
- **Eco Series** - Economic data analysis
- **Image Series** - Pattern recognition
- **Custom X/P/S Series** - Experimental approaches

---

## Resources & Further Reading

### Internal Documentation
- [Engine Documentation](ENGINE.md) - Zorro platform capabilities
- [README.md](../README.md) - Project overview and setup

### External Resources
- [Zorro Manual](https://zorro-project.com/manual/) - Official documentation
- [Financial Hacker Blog](https://financial-hacker.com) - Strategy development tutorials
- [Zorro Forum](https://opserver.de/ubb7/) - Community support

### Recommended Learning Path

1. Read Workshop series source code
2. Study Alice series progression
3. Experiment with Trend strategies
4. Explore G12 currency strength concept
5. Dive into machine learning with Alice4
6. Master risk management with Python utilities

---

## Contributing

To add new strategies to the collection:

1. Place C strategies in `algos/` directory
2. Follow naming conventions (e.g., Strategy1.c, Strategy2.c)
3. Include comment headers describing the strategy
4. Document key parameters and logic
5. Test thoroughly in simulation before live deployment

For Python utilities:
1. Add to `algos/` with descriptive names
2. Include docstrings and type hints
3. Maintain consistency with existing OandaLib patterns
4. Update this documentation

---

## ⚠️ Risk Disclaimer

**Important**: These strategies are provided for educational and research purposes. Past performance does not guarantee future results. Always:

- Backtest thoroughly with realistic assumptions
- Paper trade before live deployment
- Use proper risk management (max 1-2% per trade)
- Understand each strategy's logic before using it
- Never trade with money you can't afford to lose

Some strategies (like Alice5a/5b) are deliberately designed to show poor risk management - **do not use these in live trading**.

---

## 📝 Summary

The Z-Trading framework provides a comprehensive suite of **362 algorithmic trading tools**:

- **326 C trading strategies** covering all major approaches
- **36 Python utilities** for operations and analysis
- Full integration with 25+ brokers and exchanges
- Machine learning and deep learning capabilities
- Professional risk management tools
- Real-time monitoring and dashboards

Whether you're learning algorithmic trading basics or deploying sophisticated HFT systems, Z-Trading provides the tools and examples to accelerate your development.

---

<p align="center">
  <sub>For questions or contributions, see the main <a href="../README.md">README</a></sub>
</p>
