// https://script.google.com/macros/s/AKfycbwsQRs3pbaJDZUWB9nfNkdcbuCjUBjfDXAOtLOtxHe_SpgLM-dNTkcJUlrP_mg7CFKq/exec?sts=write&co2=400&o2=300&pm2_5=400&temp=30.00&hum=96
// https://script.google.com/macros/s/AKfycbwsQRs3pbaJDZUWB9nfNkdcbuCjUBjfDXAOtLOtxHe_SpgLM-dNTkcJUlrP_mg7CFKq/exec?sts=read

function doGet(e) {
  Logger.log(JSON.stringify(e));

  if (Object.keys(e.parameter).length === 0) {
    return ContentService.createTextOutput('No Parameters');
  }

  var sheet_id = '...';  // Spreadsheet ID.
  var sheet_name1 = "...";  // Sheet Name in Google Sheets.

  var sheet_open = SpreadsheetApp.openById(sheet_id);
  var sheet_target1 = sheet_open.getSheetByName(sheet_name1);

  var newRow = sheet_target1.getLastRow() + 1;  // Calculate the new row number
  var rowDataLog = ['', '', '', '', '', '', '', '', '', '', ''];

  // Extract `sts` from the request
  var sts_val = e.parameter.sts ? stripQuotes(e.parameter.sts) : '';

  // Date and Time
  var Curr_Date = Utilities.formatDate(new Date(), "GMT+7", "yyyy-MM-dd HH:mm:ss"); // Utilities.formatDate(new Date(), "Asia/Jakarta", 'dd/MM/yyyy');
  //var Curr_Time = Utilities.formatDate(new Date(), "Asia/Jakarta", 'HH:mm:ss'); 

  rowDataLog[0] = Curr_Date; // Column A
  //rowDataLog[1] = Curr_Time; // Column B

  // Process Parameters
  for (var param in e.parameter) {
    Logger.log('In for loop, param=' + param);
    var value = stripQuotes(e.parameter[param]);
    Logger.log(param + ':' + e.parameter[param]);

    switch (param) {
      case 'co2':
        rowDataLog[1] = value; // Column C
        break;

      case 'o2':
        rowDataLog[2] = value; // Column D
        break;

      case 'pm2_5':
        rowDataLog[3] = value; // Column E
        break;

      case 'temp':
        rowDataLog[4] = value; // Column F
        break;

      case 'hum':
        rowDataLog[5] = value; // Column G
        break;
      case 'modes':
        rowDataLog[6] = value; // Column G
        break;
      case 'maxco2':
        rowDataLog[7] = value; // Column G
        break;
      case 'minco2':
        rowDataLog[8] = value; // Column G
        break;
      case 'stopmusic':
        rowDataLog[9] = value; // Column G
        break;

      default:
        Logger.log("Unsupported parameter: " + param);
    }
  }

  // **Write Data to Google Sheets**
  if (sts_val === 'write') {
    var newRangeDataLog = sheet_target1.getRange(newRow, 1, 1, rowDataLog.length);
    newRangeDataLog.setValues([rowDataLog]);  // Add data to the new row

    return ContentService.createTextOutput('Data written successfully.');
  }

  // **Read Data for ESP32**
  if (sts_val === 'read') {
    var all_Data = sheet_target1.getDataRange().getValues();  // Read the latest data (example)
    return ContentService.createTextOutput(JSON.stringify(all_Data));
  }

  return ContentService.createTextOutput('Invalid sts value.');
}

function stripQuotes(value) {
  return value.replace(/^["']|['"]$/g, "");
}
