function generateCalendar() {
  const month = document.getElementById('month').value;
  const year = document.getElementById('year').value;

  if (!month || !year) {
      alert("Please enter both month and year.");
      return;
  }

  const daysInMonth = new Date(year, month, 0).getDate();
  const firstDay = new Date(year, month - 1, 1).getDay();
  const calendar = document.getElementById('calendar');

  let calendarHTML = '<table>';
  calendarHTML += '<tr><th>MON</th><th>TUE</th><th>WED</th><th>THU</th><th>FRI</th><th>SUT</th><th>SUN</th></tr>';
  calendarHTML += '<tr>';

  let dayOfWeek = firstDay === 0 ? 6 : firstDay - 1; // Adjust to start with Monday

  for (let i = 0; i < dayOfWeek; i++) {
      calendarHTML += '<td></td>';
  }

  for (let day = 1; day <= daysInMonth; day++) {
      calendarHTML += `<td>${day}</td>`;
      dayOfWeek++;
      if (dayOfWeek % 7 === 0) {
          calendarHTML += '</tr><tr>';
          dayOfWeek = 0;
      }
  }

  if (dayOfWeek !== 0) {
      for (let i = dayOfWeek; i < 7; i++) {
          calendarHTML += '<td></td>';
      }
  }

  calendarHTML += '</tr></table>';
  calendar.innerHTML = calendarHTML;
}