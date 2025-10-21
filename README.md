# 💹 Z-Trading

<div align="center">

![Z-Trading](https://img.shields.io/badge/Z--Trading-HFT%20Framework-blue?style=for-the-badge&logo=bitcoin)
[![C](https://img.shields.io/badge/C-Algorithms-A8B9CC?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Python](https://img.shields.io/badge/Python-3.6+-3776AB?style=for-the-badge&logo=python)](https://www.python.org)
[![Zorro](https://img.shields.io/badge/Zorro-Trading%20Engine-orange?style=for-the-badge)](https://zorro-project.com)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)

**A professional High Frequency Trading (HFT) framework for multi-venue algorithmic trading**

</div>

---

## 📖 Overview

**Z-Trading** is a comprehensive algorithmic trading framework designed for High Frequency Trading (HFT) and multi-venue execution. Built on top of the powerful **Zorro Trading Platform**, it combines the speed and efficiency of compiled C algorithms with the flexibility of Python for data analysis, risk management, and visualization.

The framework provides asynchronous low-latency operations perfect for ultra-fast Market Making (MM) and Market Taking (MT) strategies. With over **360 pre-built algorithms** and support for **10+ trading APIs**, Z-Trading enables traders to develop, backtest, and deploy robust quantitative strategies across multiple asset classes.

## ✨ Features

- ⚡ **High Frequency Trading** - Ultra-low-latency C-based execution engine
- 🎯 **Multi-Venue Support** - Trade across 10+ broker APIs and exchanges
- 📊 **360+ Algorithms** - Pre-built trading strategies and indicators
- 🐍 **Python Bridge** - Seamless integration between C and Python engines
- 🔗 **OANDA API Integration** - Professional forex and CFD trading
- 📈 **Live Dashboards** - Real-time monitoring via Google Sheets
- 🗄️ **MySQL Database** - Store and analyze historical trading data
- 💰 **Risk Management** - Advanced position sizing and portfolio optimization
- 🌍 **Multi-Asset Support** - Trade forex, stocks, indices, commodities, bonds, and crypto
- 🔄 **Backtesting Engine** - Test strategies with historical data
- ⚙️ **Low-Latency Operations** - Async execution for maximum speed
- 📉 **Statistical Analysis** - Volatility, correlation, and performance analytics
- 🤖 **AI Integration** - Compatible with Keras and PyTorch models
- 📊 **Trade Profiling** - Detailed performance metrics and visualization
- 🔐 **Secure Configuration** - Environment-based credentials management

## 📦 Installation

### Prerequisites

- **Zorro Trading Platform** (version 1.68.62 or higher)
- **Python 3.6+** with pip or poetry
- **MySQL Server** (optional, for database features)
- **OANDA Account** (for live trading)
- **Google Cloud Service Account** (for Sheets integration)

### Quick Start

```bash
# Clone the repository
git clone https://github.com/alexcolls/z-trading.git
cd z-trading

# Install Python dependencies with Poetry (recommended)
poetry install

# Or with pip
pip install oandapyV20 pandas pygsheets gspread oauth2client sqlalchemy pymysql

# Configure environment variables
cp .env.sample .env
# Edit .env with your API credentials
```

### Zorro Engine Setup

1. **Install Zorro**: Extract the `engine/` contents to your Zorro installation directory
2. **Copy Algorithms**: Place C scripts from `algos/` into Zorro's `Strategy/` folder
3. **Configure APIs**: Edit `Zorro.ini` with your broker credentials
4. **Verify Installation**: Run `engine/Zorro.exe` and load a test strategy

## ⚙️ Configuration

### Environment Variables

Create a `.env.sample` file in the root directory:

```env
# OANDA API Credentials
OANDA_TOKEN=your_oanda_api_token
OANDA_ACCOUNT_ID=your_account_id

# Google Sheets API
GOOGLE_SERVICE_ACCOUNT_FILE=path/to/service_account.json
GOOGLE_SHEET_NAME=TradingDashboard

# MySQL Database
MYSQL_HOST=localhost
MYSQL_USER=your_username
MYSQL_PASSWORD=your_password
MYSQL_DATABASE=trading_db

# Risk Management
HARD_STOP_PERCENT=2.0
INITIAL_BALANCE=10000
```

### Google Sheets Setup

1. Create a Google Cloud Project and enable Google Sheets API
2. Download service account JSON credentials
3. Place credentials as `algos/GS_main.json` and `algos/GS_trader1.json`
4. Share your Google Sheet with the service account email

### MySQL Database Setup

```sql
-- Create databases for statistics and correlations
CREATE DATABASE OandaEurope_Statistics;
CREATE DATABASE OandaEurope_Correlations;

-- Import schema (example)
USE OandaEurope_Statistics;
CREATE TABLE AvgVolatilities (
    Symbol VARCHAR(20) PRIMARY KEY,
    -- Add your columns for different timeframes
);
```

## 🎯 Usage

### Running C Algorithms with Zorro

```c
// Example: Simple trend trading strategy
#include <profile.c>

function run()
{
    vars Price = series(price());
    vars Trend = series(LowPass(Price, 500));
    
    Stop = 4*ATR(100);
    
    if(valley(Trend))
        enterLong();
    else if(peak(Trend))
        enterShort();
    
    StartDate = 2020;
    EndDate = 2024;
    asset("EUR/USD");
    
    set(LOGFILE);
}
```

**Run via Zorro GUI:**
1. Open `Zorro.exe`
2. Select your script from the dropdown
3. Choose Trade/Test/Train mode
4. Click "Run"

### Python Trading Dashboard

```bash
# Start the trader dashboard
poetry run python algos/TraderDashboard.py

# Or directly with Python
python algos/TraderDashboard.py
```

The dashboard will prompt for:
- OANDA API Token
- Account ID
- Google Sheet name
- Update frequency (seconds)

### Risk Management System

```bash
# Run the risk manager
poetry run python algos/RiskManager.py
```

This calculates:
- Maximum position sizes per instrument
- Portfolio correlation adjustments
- Volatility-based sizing
- Exposure levels and warnings

### Python Library Usage

```python
from algos.OandaLib import Oanda_Prices, Oanda_Candles, GSapi

# Get real-time prices for all symbols
prices = Oanda_Prices(account_id, {'instruments': 'EUR_USD,GBP_USD'})

# Fetch historical candles
candles = Oanda_Candles('EUR_USD', {
    'granularity': 'H1',
    'count': 500
})

# Update Google Sheets
gs = GSapi('OandaEurope', 'Dashboard')
gs.update_value('A1', 'Hello Trading!')
```

## 🏗️ Architecture

### Tech Stack

- **Zorro Trading Platform** - C-based trading engine and backtesting framework
- **C Language** - High-performance algorithm development
- **Python 3.6+** - Data analysis, dashboards, and utilities
- **OANDA v20 API** - Market data and order execution
- **Google Sheets API** - Real-time dashboards and monitoring
- **MySQL / SQLAlchemy** - Data storage and retrieval
- **Pandas** - Time series analysis and data manipulation
- **PyGsheets / Gspread** - Google Sheets integration

### Project Structure

```
z-trading/
├── algos/                    # Trading algorithms and utilities (362 files)
│   ├── *.c                   # C trading strategies (326 files)
│   │   ├── Alice*.c          # Alice strategy variations
│   │   ├── Allocation*.c     # Portfolio allocation strategies
│   │   ├── BB*.c             # Bollinger Band strategies
│   │   ├── Benchmark.c       # Performance benchmarking
│   │   └── ...               # 320+ more strategies
│   ├── *.py                  # Python utilities (36 files)
│   │   ├── OandaLib.py       # OANDA API wrapper
│   │   ├── TraderDashboard.py    # Live trading monitor
│   │   ├── RiskManager.py    # Position sizing & risk
│   │   ├── Correlations.py   # Correlation analysis
│   │   ├── Volatility.py     # Volatility calculations
│   │   └── GoogleService.py  # Google Sheets integration
│   └── *.json                # Service account credentials
│
├── engine/                   # Zorro trading platform
│   ├── Zorro.exe             # Main trading application
│   ├── Zview.exe             # Chart viewer
│   ├── ZOptimizer.exe        # Strategy optimizer
│   ├── *.dll                 # Required libraries
│   ├── include/              # C header files
│   │   ├── trading.h         # Core trading functions
│   │   ├── functions.h       # Math and indicators
│   │   ├── zorro.h           # Platform API
│   │   └── ...               # Additional headers
│   └── Plugin/               # Broker API plugins
│
├── .env.sample               # Environment configuration template
├── LICENSE                   # MIT License
└── README.md                 # This file
```

### Key Components

#### **TraderDashboard.py**
Real-time trading dashboard that monitors:
- Account balance and NAV
- Open positions and P&L
- Margin usage and available capital
- Position sizing recommendations
- Updates Google Sheets automatically

#### **RiskManager.py**
Advanced risk management system featuring:
- Volatility-based position sizing
- Correlation-adjusted exposure limits
- Maximum position calculations per instrument
- Portfolio-level risk monitoring
- Integration with Google Sheets for live updates

#### **OandaLib.py**
Python wrapper for OANDA API providing:
- Real-time pricing for 120+ instruments
- Historical candlestick data
- Spread analysis
- Position management
- Google Sheets data export

#### **C Trading Algorithms**
Over 326 compiled C strategies including:
- Trend following (Alice series)
- Mean reversion
- Breakout systems
- Statistical arbitrage
- Machine learning integrations
- Custom indicators (Ehlers, Accelerator, etc.)

## 🌍 Supported Markets & Instruments

### Forex (120+ pairs)
**Major Pairs:** EUR/USD, GBP/USD, USD/JPY, AUD/USD, NZD/USD, USD/CAD, USD/CHF

**Cross Pairs:** EUR/GBP, EUR/JPY, GBP/JPY, AUD/JPY, EUR/AUD, GBP/AUD, and more

**Exotic Pairs:** USD/CNH, USD/MXN, USD/TRY, USD/ZAR, USD/THB, USD/INR, etc.

### Indices
- **US:** SPX500, NAS100, US30, US2000
- **Europe:** EU50, DE30, FR40, UK100, NL25
- **Asia-Pacific:** JP225, HK33, CN50, AU200, IN50, SG30, TWIX

### Commodities
- **Energy:** WTICO (Crude Oil), BCO (Brent), NATGAS (Natural Gas)
- **Metals:** XAU (Gold), XAG (Silver), XPT (Platinum), XPD (Palladium), XCU (Copper)
- **Agriculture:** CORN, WHEAT, SOYBN (Soybeans), SUGAR

### Bonds
- **US Treasuries:** USB02Y, USB05Y, USB10Y, USB30Y
- **European Bonds:** DE10YB (German Bund), UK10YB (UK Gilt)

### Precious Metals Crosses
XAU/AUD, XAU/CAD, XAU/CHF, XAU/EUR, XAU/GBP, XAU/JPY, XAU/XAG, and more

## 🔧 Advanced Features

### Backtesting

Run historical simulations with the Zorro engine:

```c
function run()
{
    StartDate = 20200101;  // YYYYMMDD format
    EndDate = 20241231;
    BarPeriod = 60;        // 1-hour bars
    
    // Your strategy logic here
    
    set(LOGFILE | PLOTNOW);
}
```

### Walk-Forward Optimization

```c
function run()
{
    NumYears = 4;
    NumWFOCycles = 10;
    
    // Strategy parameters
    var Period = optimize(20, 10, 100, 10);
    
    set(WFO);
}
```

### Machine Learning Integration

```python
# Train a model with historical data
from algos.DataFromC import load_zorro_data
import tensorflow as tf

# Load data exported from Zorro
df = load_zorro_data('EUR_USD.csv')

# Build and train your model
model = tf.keras.Sequential([...])
model.fit(X_train, y_train)

# Export predictions back to Zorro
model.predict(X_test).to_csv('predictions.csv')
```

### Multi-Strategy Portfolio

Run multiple strategies simultaneously with portfolio-level risk management:

```c
// Portfolio manager script
function run()
{
    // Allocate capital across strategies
    Lots = PortfolioLots("Strategy1", 0.3);
    Lots = PortfolioLots("Strategy2", 0.4);
    Lots = PortfolioLots("Strategy3", 0.3);
}
```

## 📊 Dashboard & Monitoring

The integrated Google Sheets dashboards provide:

- **Account Overview**: Balance, NAV, P&L, margin usage
- **Position Monitor**: Live positions with entry price, current P&L, and size
- **Risk Metrics**: Exposure by instrument, correlation matrix, VAR calculations
- **Performance Stats**: Win rate, Sharpe ratio, max drawdown, profit factor
- **Market Data**: Real-time prices, spreads, volatility measures

Access your dashboard at your configured Google Sheet URL.

## ⚠️ Risk Warning & Disclaimer

**IMPORTANT: PLEASE READ CAREFULLY**

Trading financial instruments involves substantial risk and may not be suitable for all investors. The high degree of leverage can work against you as well as for you. Before deciding to trade, you should carefully consider your investment objectives, level of experience, and risk appetite.

### Key Risks:
- 📉 **Loss of Capital**: You may lose some or all of your initial investment
- 💸 **Leverage Risk**: Leveraged trading can magnify both gains and losses
- 📊 **Market Risk**: Market volatility can result in rapid losses
- ⚙️ **Technical Risk**: Software bugs or system failures may impact trading
- 🌐 **Liquidity Risk**: Some instruments may have limited liquidity

### Legal Disclaimer:
- This software is provided for **educational and research purposes only**
- Past performance is **not indicative** of future results
- The authors and contributors are **not liable** for any trading losses
- Always conduct your own research and consult financial advisors
- Use at your own risk in live trading environments
- Comply with all applicable laws and regulations in your jurisdiction

**By using this software, you acknowledge that you understand these risks and accept full responsibility for your trading decisions.**

## 🤝 Contributing

Contributions are welcome! Whether you want to:

- 🐛 Report bugs or issues
- 💡 Suggest new features or strategies
- 📝 Improve documentation
- 🔧 Submit code improvements
- 📊 Share trading strategies

### How to Contribute

1. **Fork the repository**
2. **Create your feature branch** (`git checkout -b feature/AmazingStrategy`)
3. **Commit your changes** (`git commit -m '✨ Add new momentum strategy'`)
4. **Push to the branch** (`git push origin feature/AmazingStrategy`)
5. **Open a Pull Request**

### Development Guidelines

- Follow C99 standards for algorithm development
- Use PEP 8 style guide for Python code
- Test strategies thoroughly in simulation before live trading
- Document your code with clear comments
- Never commit API keys or credentials

## 📄 License

[MIT License](LICENSE)

Copyright (c) 2022 quantium

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHOR OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## 🙏 Acknowledgments

Built with:
- [Zorro Trading Platform](https://zorro-project.com) - Professional algorithmic trading software
- [OANDA](https://www.oanda.com) - Forex and CFD trading API
- [Python](https://www.python.org) - Data analysis and automation
- [Pandas](https://pandas.pydata.org) - Time series analysis
- [Google Sheets API](https://developers.google.com/sheets/api) - Real-time dashboards
- [MySQL](https://www.mysql.com) - Database management

Special thanks to the algorithmic trading community for inspiration and support.

---

## 📞 Support & Contact

- **Twitter**: [@fxmozart_sol](https://twitter.com/fxmozart_sol)
- **Issues**: [GitHub Issues](https://github.com/alexcolls/z-trading/issues)
- **Discussions**: [GitHub Discussions](https://github.com/alexcolls/z-trading/discussions)

For collaboration opportunities, reach out via Twitter!

---

## ⭐ Show Your Support

If this project helped you with your algorithmic trading journey, please consider:

- ⭐ **Starring the repository**
- 🐛 **Reporting bugs and issues**
- 💡 **Suggesting new features**
- 🤝 **Contributing strategies**
- 📢 **Sharing with the trading community**
- 💬 **Joining discussions**

---

<p align="center">
  <b>Made with 💹 and ⚡ for Algorithmic Trading</b><br>
  <i>Trade smarter, faster, and more efficiently</i>
</p>

<p align="center">
  <sub>© 2022 Z-Trading | MIT License</sub>
</p>
