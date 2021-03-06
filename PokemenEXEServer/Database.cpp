#include "stdafx.h"
#include "Database.h"

Database::Database() :
    m_mysql(), m_locker()
{
	mysql_init(&m_mysql);
}

Database::~Database()
{
	Disconnect();
}

bool Database::Connect(const std::string& user, const std::string& password, const std::string& database)
{
    if (mysql_real_connect(&m_mysql, "localhost",
		user.c_str(), password.c_str(), database.c_str(),
		0, NULL, 0))
        return true;
    return false;
}

void Database::Disconnect()
{
	mysql_close(&m_mysql);
}

bool Database::Insert(const std::string& query)
{
	m_locker.lock();
	int ret = mysql_real_query(&m_mysql, query.c_str(), (unsigned long)query.size());
	m_locker.unlock();
	if (!ret)
		return true;
	return false;
}

bool Database::Update(const std::string& query)
{
	m_locker.lock();
	int ret = mysql_real_query(&m_mysql, query.c_str(), (unsigned long)query.size());
	m_locker.unlock();
	if (!ret)
		return true;
	return false;
}

bool Database::Delete(const std::string & query)
{
	m_locker.lock();
	int ret = mysql_real_query(&m_mysql, query.c_str(), (unsigned long)query.size());
	m_locker.unlock();
	if (!ret)
		return true;
	return false;
}

std::vector<std::string> Database::Select(const std::string& query, int valueCnt)
{
    MYSQL_RES *sqlResult = NULL;
    MYSQL_ROW sqlRow;

    std::vector<std::string> queryResult;
	std::string rowResult;
	m_locker.lock();
    int iRetVal = mysql_real_query(&m_mysql, query.c_str(), (unsigned long)query.size());
    if (!iRetVal)
    {
		sqlResult = mysql_store_result(&m_mysql);
		if (sqlResult)
		{
			while (sqlRow = mysql_fetch_row(sqlResult))
			{
				rowResult.clear();
				for (int i = 0; i < valueCnt; ++i)
					rowResult += sqlRow[i] + std::string{ "\n" };
				queryResult.push_back(rowResult);
			}
		}
    }

    if (sqlResult != NULL)
        mysql_free_result(sqlResult);
    sqlResult = NULL;
	m_locker.unlock();
    return queryResult;
}

