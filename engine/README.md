# 🚀 Zorro Trading Engine

## Overview

Zorro is an ecosystem for financial research and algorithmic trading. It is not a 'robot' and not a trading platform, but has some elements of both. Its main purpose is data analysis and algorithmic trading with C or C++ scripts in automated or semi-automated mode. 

Technically it's a front end to a C or C++ compiler and a set of modules for time series analysis, machine learning, optimization, and online broker or data source access. It allows with a few button clicks to edit trading strategy scripts, train machine learning algorithms, optimize and backtest systems with several methods, and trade them live.

---

## 🔧 Core Features

### C/C++ Script Compiler

- **Compiler Choice**: lite-C or VC++, 32 or 64 bit ([code examples](https://zorro-project.com))
- **High Speed**: ~750 ns latency in HFT mode
- **Direct Access**: Windows API and external DLLs
- **Language Integration**: Direct access to R and Python functions and libraries
- **Native Support**: Time series, datasets, matrices, fuzzy logic
- **Multi-Core**: Multiple CPU cores for optimizing and machine learning
- **Custom UI**: Individual spreadsheet-based user interfaces
- **Debugger**: Single-step visual debugger for analyzing strategies
- **Integration Toolkit**: Run Zorro scripts from external software

---

## 📊 Data Analysis

### Technical Analysis
- **300+ Indicators** and time series analysis functions
- **Pattern Detection**: Frechet pattern detection
- **Signal Processing**: Spectral analysis capabilities
- **Predictive Analytics**: Parabolic regression for predicting peaks and crossovers
- **Market Structure**: Support and resistance lines, divergence/convergence detection
- **Market Analysis**: Market sentiment, currency strength, seasonal strength analysis
- **Randomization**: Monte Carlo algorithms, bootstrap and shuffle randomizing

---

## 🤖 Machine Learning

### Deep Learning Frameworks
- **Torch**: Native integration
- **Keras**: Full support
- **TensorFlow**: Direct access
- **MxNet**: Compatible
- **H2O**: Integration ready
- **Deepnet**: Supported

### Native ML Capabilities
- Native perceptron support
- Pattern recognition
- Decision tree algorithms
- Fuzzy logic support
- **Code Export**: Machine generated algorithms can be exported to C code

---

## 📥 Data Import

### Data Sources
- **Level I, Level 2, and Options Data**: Import from CSV and JSON
- **Supplementary Data**: COT, yield, earnings, blockchains
- **Web Scraping**: Content import from HTML websites

---

## 🌐 Broker & Data Connections

### Data Feeds
- **AlphaVantage**: Market data
- **CryptoCompare**: Cryptocurrency data
- **IEX**: Exchange data
- **DTN IQFeed**: Professional data feed
- **Stooq**: Historical data

### Direct Broker Connections
- **Alpaca**: Commission-free trading
- **Dukascopy**: Swiss forex bank
- **Finvasia**: Indian broker
- **FXCM**: Forex and CFD trading
- **IG**: Multi-asset broker
- **Interactive Brokers**: Professional trading platform
- **Oanda**: Forex and CFD broker
- **Rithmic**: Professional futures
- **TDA/Schwab**: US stocks and options
- **TradeStation**: Advanced trading platform
- **Tradier**: Brokerage API

### Platform Connections
- **IBKR TWS**: Interactive Brokers Trader Workstation
- **MT4**: MetaTrader 4 platform
- **MT5**: MetaTrader 5 platform

### Digital Coin Exchanges
- **Binance**: World's largest crypto exchange
- **Bitfinex**: Advanced crypto trading
- **Bittrex**: US crypto exchange
- **Coinigy**: Multi-exchange platform
- **Deribit**: Options and futures
- **Kraken**: Established crypto exchange

### API Interface
- **Open Source Interface**: For all API, REST, and FIX connections
- **Custom Plugins**: User-written plugins available (not subject to official support)

> **Note**: Brands and trademarks are property of their owners and not affiliated with oP group Germany. Some broker/platform API plugins are written by users and may be subject to other restrictions or additional fees.

---

## ⚙️ Trading Engine

### Time Frames & Execution
- **Time Frames**: From 1 millisecond to 1 week
- **Multi-Connection**: Simultaneous connection to multiple brokers and data feeds
- **Account Management**: Account/asset lists with symbol mapping and individual parameters

### Options Trading
- **Options/Combos**: Full support
- **Greeks Calculation**: IV, Delta, and all Greeks
- **Advanced Strategies**: Complex multi-leg options strategies

### Position Management
- **NFA/FIFO Compliance**: Regulatory compliance built-in
- **Virtual Hedging**: For concurrent opposite positions
- **Automated Training**: Background training and optimizing while live trading
- **Phantom Trades**: Skip drawdown periods ("Equity Curve Trading")

### High-Frequency Trading
- **Special HFT Mode**: Optimized for high frequency trading backtests
- **Ultra-Low Latency**: ~750 ns execution latency

---

## 🧪 Test & Optimization

### Performance
- **World's Fastest Optimizer**: 25 seconds for 12 parameters*
- **World's Fastest Backtester**: 0.3 seconds for 10 years at tick level*

### Bar Types
- **Standard**: Time-based bars
- **Range Bars**: Price-range based
- **Renko**: Trend-following brick charts
- **Point-and-Figure**: Classic charting
- **User-Defined**: Custom bar types

### Optimization Methods
- **Ascent**: Hill climbing optimization
- **Brute Force**: Exhaustive search
- **Genetic**: Evolutionary algorithms
- **User-Defined**: Custom optimization methods

### Simulation Features
- **Precise Broker Simulation**: Fees, leverage, swaps, slippage
- **Oversampling & Detrending**: On price, signal, or trade level
- **Individual Optimization**: Per portfolio component
- **Capital Allocation**: MVO or OptimalF algorithms
- **Walk Forward Analysis**: Rolling and anchored methods

---

## 📈 Charting & Reports

### Performance Reports
- **Detailed Analytics**: Comprehensive performance metrics
- **Monte Carlo Analysis**: Risk assessment and probability analysis
- **Reality Check**: Randomized price or equity curves

### Interactive Charting
- **Chart Viewer**: Zoom, step, and replay functions
- **Multiple Chart Types**: Candle, bar, contour, heatmap, scatter plots
- **Analysis Plots**: MAE/MFE, profit, season, option payoff, parameter histograms

### Export Capabilities
- **Spreadsheet Export**: Indicators, charts, and trade lists
- **Live Status**: Web page reports
- **Email Notifications**: Automated trading status reports

---

## 🎮 Process Control

### Integration Options
- **DLL Integration**: Embed in external software
- **Batch Control**: Full control with batch files
- **Statistics**: Multiple backtests for analysis
- **Multi-Zorro Networks**: Local PC or cloud deployment

---

## 📚 Ready-to-Run Strategies

### Pre-Built Trading Systems

**Z1**: Trend detecting Forex/CFD trading system

**Z2**: Mean reversion Forex/CFD system with spectral analysis

**Z7**: Pattern detection Forex system using machine learning

**Z8**: Long-term MVO-based stock/ETF portfolio rotation

**Z9**: Long-term momentum based sector ETF portfolio rotation

**Z10**: MVO cryptocurrency trading system

**Z12**: Anticorrelation based trend/countertrend system

**Z13**: Options combo selling system

> For detailed strategy information, visit the [official Zorro documentation](https://zorro-project.com)

---

## 📊 Performance Benchmarks

### Speed Tests*

**Backtesting Performance**:
- 0.3 seconds for backtesting a simple RSI strategy (Benchmark.c example)
- Tick mode with 10 years of M1 data
- Simple moving average crossover system

**Optimization Performance**:
- 25 seconds for walk-forward optimizing a 12-parameter multi-asset strategy
- OptimizeTest.c example on 4-hour bars
- 10 years of M1 data

**Test Environment**:
- Zorro S on 2.6 GHz Intel i7 system
- Multi-core optimization enabled

*Actual performance may vary based on hardware configuration and strategy complexity.

---

## ⚠️ Risk Disclaimer

Algorithmic trading has large potential rewards, but also large potential risk. You must be aware of the risks and be willing to accept them in order to invest in algorithmic strategies. 

**Important Considerations**:
- Don't trade with money you can't afford to lose
- Past performance is not indicative of future results
- Always test strategies thoroughly before live trading
- Understand the risks of leverage and margin trading
- Comply with all applicable regulations in your jurisdiction

---

## 🔗 Resources

- **Official Website**: [zorro-project.com](https://zorro-project.com)
- **Documentation**: [Zorro Manual](https://zorro-project.com/manual/)
- **Forum**: [Zorro Community Forum](https://financial-hacker.com)
- **Support**: Check specific plugin pages in the manual for details

---

## 📝 Notes

- Some broker/platform API plugins are written by community users
- Third-party plugins may not be subject to official Zorro support
- Additional fees or restrictions may apply to certain broker connections
- Always verify broker availability and terms in your jurisdiction

---

<p align="center">
  <sub>Zorro is developed by oP group Germany</sub><br>
  <sub>All trademarks are property of their respective owners</sub>
</p>
