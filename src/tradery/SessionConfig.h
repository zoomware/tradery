/*
Copyright (C) 2018 Adrian Michel
http://www.amichel.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <misc.h>
#include <strings.h>

class SessionConfig {
 private:
  const UniqueId _sessionId;
  const std::string _sessionIdString;
  const std::string _sessionPath;
  const std::string _chartRootPath;
  UniqueIdVector _runnables;
  std::vector<std::string> _systemFileNames;
  const std::string _errorsFile;
  const std::string _symbolsFileName;
  const std::string _runtimeStatsFile;
  const std::string _tradesFile;
  const std::string _tradesDescriptionFile;
  const std::string _tradesCSVFile;
  const std::string _symbolsToChartFile;
  const std::string _chartDescriptionFile;
  const std::string _signalsFile;
  const std::string _signalsCSVFile;
  const std::string _signalsDescriptionFile;
  const std::string _statsFile;
  const std::string _statsCSVFile;
  const std::string _outputFile;
  const std::string _equityCurveFile;
  const std::string _heartBeatFile;
  const std::string _reverseHeartBeatFile;
  const std::string _cancelFile;
  const std::string _endRunFile;
  const std::string _generatedDefinesFile;

 public:
  SessionConfig(const std::string& outputPath)
      : SessionConfig(UniqueId().toString(), outputPath) {}

  SessionConfig(const std::string& sessionId, const std::string& outputPath)
      : _sessionId(sessionId),
        _sessionIdString(_sessionId),
        _sessionPath(tradery::addFSlash(
            tradery::addFSlash(tradery::addFSlash(outputPath)) +
            _sessionIdString)),
        _chartRootPath(tradery::addFSlash(_sessionPath) + "charts"),
        _errorsFile(_sessionPath + "errors.htm"),
        _symbolsFileName(_sessionPath + "symbols.txt"),
        _runtimeStatsFile(_sessionPath + "runtimeStats.txt"),
        _tradesFile(_sessionPath + "trades.htm"),
        _tradesDescriptionFile(_sessionPath + "tradesDesc.txt"),
        _tradesCSVFile(_sessionPath + "trades.csv"),
        _symbolsToChartFile(_sessionPath + "symbolstochartfile.txt"),
        _chartDescriptionFile(_chartRootPath + "charts_description.xml"),
        _signalsFile(_sessionPath + "signals.htm"),
        _signalsCSVFile(_sessionPath + "signals.csv"),
        _signalsDescriptionFile(_sessionPath + "signalsDesc.txt"),
        _statsFile(_sessionPath + "stats.htm"),
        _statsCSVFile(_sessionPath + "stats.csv"),
        _outputFile(_sessionPath + "output.txt"),
        _equityCurveFile(_sessionPath + "equityCurve"),
        _heartBeatFile(_sessionPath + "heartBeat.txt"),
        _reverseHeartBeatFile(_sessionPath + "reverseHeartBeat.txt"),
        _cancelFile(_sessionPath + "cancel.txt"),
        _endRunFile(_sessionPath + "endRun.txt"),
        _generatedDefinesFile(_sessionPath + "defines.h") {}

  bool hasRunnables() const { return !_runnables.empty(); }
  void addRunnableId(const UniqueId& id) { _runnables.push_back(id); }
  const UniqueIdVector& getRunnables() const { return _runnables; }
  bool hasSessionPath() const { return !_sessionPath.empty(); }
  /*	bool generateTrades() const { return __super::generateTrades; }
          bool generateEquityCurve() const { return
     __super::generateEquityCurve; } bool generateStats() const { return
     __super::generateStats; } bool generateCharts() const { return
     __super::generateCharts; }
          */

  const std::string& getSessionId() const { return _sessionIdString; }

  const std::string& getSessionPath() const { return _sessionPath; }

  const std::string& getErrorsFile() const { return _errorsFile; }

  const std::string& getSymbolsFileName() const { return _symbolsFileName; }

  const std::string& getRuntimeStatsFile() const { return _runtimeStatsFile; }

  const std::string& getTradesFile() const { return _tradesFile; }

  const std::string& getTradesDescriptionFile() const {
    return _tradesDescriptionFile;
  }

  const std::string& getTradesCSVFile() const { return _tradesCSVFile; }

  const std::string& getSymbolsToChartFile() const {
    return _symbolsToChartFile;
  }

  const std::string& getChartRootPath() const { return _chartRootPath; }

  const std::string& getChartDescriptionFile() const {
    return _chartDescriptionFile;
  }

  const std::string& getSignalsFile() const { return _signalsFile; }

  const std::string& getSignalsCSVFile() const { return _signalsCSVFile; }

  const std::string& getSignalsDescriptionFile() const {
    return _signalsDescriptionFile;
  }

  const std::string& getStatsFile() const { return _statsFile; }
  const std::string& getStatsCSVFile() const { return _statsCSVFile; }

  const std::string& getOutputFile() const { return _outputFile; }

  const std::string& getEquityCurveFile() const { return _equityCurveFile; }

  const std::string& getHeartBeatFile() const { return _heartBeatFile; }
  const std::string& getReverseHeartBeatFile() const {
    return _reverseHeartBeatFile;
  }
  const std::string& getCancelFile() const { return _cancelFile; }

  const std::string& getEndRunFile() const { return _endRunFile; }

  bool hasEndRunFile() const { return !_endRunFile.empty(); }

  const std::string& getGeneratedDefinesFile() const {
    return _generatedDefinesFile;
  }
};

typedef boost::shared_ptr<SessionConfig> SessionConfigPtr;